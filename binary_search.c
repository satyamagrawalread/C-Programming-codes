#include<stdio.h>
#include<stdlib.h>


void binary(int a[], int n, int key)
{
    int lower_bound=0;
    int upper_bound=n-1;
    int middle=(lower_bound + upper_bound)/2;
    int comparisons=1;
    while(upper_bound>=lower_bound)
    {
        if(a[middle]==key)
        {
            printf("Element searched is present\n");
            printf("No. of comparisons: %d", comparisons);
            return;
        }
        else if(a[middle]>key)
        {
            upper_bound=middle-1;
        }
        else
        {
            lower_bound=middle+1;
        }
        middle=(lower_bound + upper_bound)/2;
        comparisons+=1;
    }
    printf("Element is not found\n");
    printf("No. of comparisons: %d", comparisons);
}


int main()
{
    printf("Enter the number to be given: ");
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to be searched: ");
    int key;
    scanf("%d", &key);
    binary(a, n, key);
    return 0;
    
}