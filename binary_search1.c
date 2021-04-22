#include<stdio.h>
#include<stdlib.h>


int binary(int a[], int lower_bound, int upper_bound, int key)
{
    if(upper_bound<lower_bound)
    {
        printf("Element not found\n");
        return 0;
    }
    int middle=(lower_bound + upper_bound)/2;
    if(a[middle]==key)
    {
        printf("Element searched is present\n");
        printf("Element found at index: %d\n", middle);
        return 1;
    }
    else if(a[middle]>key)
    {
        return 1+binary(a, lower_bound, middle-1, key);
    }
    else
    {
        return 1+binary(a, middle+1, upper_bound, key);
    }
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
    printf("No. of Comparisons: %d", binary(a,0, n-1, key));
    return 0;
    
}