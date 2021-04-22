#include <stdio.h>

struct object
{
    int weight;
    int profit;
    float pbw;
};

void merge(struct object *arr, int lo, int mid, int hi)
{
    int n1 = mid - lo + 1, n2 = hi - mid;
    struct object left[n1], right[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[lo + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = lo;

    while (i < n1 && j < n2)
    {
        if (left[i].pbw > right[j].pbw)
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = left[i++];
    }
    while (j < n2)
    {
        arr[k++] = right[j++];
    }
}

void mergeSort(struct object *arr, int lo, int hi)
{
    if (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        mergeSort(arr, lo, mid);
        mergeSort(arr, mid + 1, hi);
        merge(arr, lo, mid, hi);
    }
}

void print_info(int n, struct object *objects)
{
    printf("sr no.\tWeights\tProfits\tProfit/Weight\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%0.2f\n", i + 1, objects[i].weight, objects[i].profit, objects[i].pbw);
    }
}

void fractional_knapsack(int n, struct object *objects, int W)
{
    printf("\n\nBefore Sorting the entries: \n");
    print_info(n, objects);

    mergeSort(objects, 0, n - 1);
    printf("\n\nAfter Sorting the entries: \n");
    print_info(n, objects);

    int total_w = 0;
    float total_p = 0;
    float used[n];
    int i = 0;
    for (int i = 0; i < n; i++)
    {
        if (objects[i].weight <= W - total_w)
        {
            used[i] = 1;
            total_w += objects[i].weight;
            total_p += objects[i].profit;
        }
        else
        {
            int rem_w = W - total_w;
            total_w += rem_w;
            total_p += objects[i].pbw * rem_w;
            used[i] = (float)rem_w / objects[i].weight;
        }
    }
    printf("\nFractions of objects included : ");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f\t", used[i]);
    }
    printf("Maximum Profit that can be made : %.2f", total_p);
}

int main(int argc, char *argv[])
{
    int n, W;
    printf("Enter no. of objects :");
    scanf("%d", &n);

    struct object objects[n];
    for (int i = 0; i < n; i++)
    {
        struct object obj;
        printf("Enter Weight of product %d :", i + 1);
        scanf("%d", &obj.weight);
        printf("Enter Profit of product %d :", i + 1);
        scanf("%d", &obj.profit);
        obj.pbw = (float)obj.profit / obj.weight;
        objects[i] = obj;
        printf("\n\n");
    }

    printf("Enter threshould weight of knapsack :");
    scanf("%d", &W);

    fractional_knapsack(n, objects, W);

    return 0;
}
