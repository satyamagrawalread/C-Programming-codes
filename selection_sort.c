#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    printf("Enter the size of array: ");
    int n;
    scanf("%d",&n);
    int *array=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d", &array[i]);
    }
    int comp=0, swap=0;
    int min, min_index;
    int t,k;
    for(int i=0;i<n-1;i++)
    {
        k=0;
        min=array[i];
        for(int j=i+1;j<n;j++)
        {
            if(min>array[j])
            {
                min=array[j];
                min_index=j;
                k=1;
            }
            comp+=1;
        }
        if(k==1)
        {
            t=array[i];
            array[i]=array[min_index];
            array[min_index]=t;
            swap+=1;
        }
    }
    printf("Sorted Elements are: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ", array[i]);
    }
    printf("\nNo. of comparisons: %d", comp);
    printf("\nNo. of swappings: %d\n", swap);
    return 0;
}