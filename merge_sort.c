#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int comp=0;

int merge(int *A, int start, int middle, int end)
{
    int p=start;
    int q=middle+1;
    int *B=(int*)malloc((end-start+1)*sizeof(int));
    int k=0;
    while(p<=middle && q<=end)
    {
        comp+=1;
        if(A[p]<A[q])
        {
            B[k++]=A[p++];
        }
        else if(A[p]>A[q])
        {
            B[k++]=A[q++];
        }
        else
        {
            B[k++]=A[p++];
            B[k++]=A[q++];
        }
    }
    while(p<=middle)
    {
        comp+=1;
        B[k++]=A[p++];
    }
    while(q<=end)
    {
        comp+=1;
        B[k++]=A[q++];
    }
    k=0;
    for(int i=start;i<=end;i++)
    {
        A[i]=B[k++];
    }
    return comp;
}

void sort(int A[], int start, int end)
{
    if(start==end)
    {
        return;
    }
    int middle=(start + end)/2;
    sort(A, start, middle);
    sort(A, middle+1, end);
    merge(A, start, middle, end);
}
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the numbers to be sorted: ");
    int *A=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d", &A[i]);
    }
    sort(A, 0, n-1);
    printf("The Sorted elements: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ", A[i]);
    }
    printf("\nNo. of comparisons: %d", comp);
    return 0;
}