//Insertion Sort
//Time Complexity = O(N^2)
//Space Complexity = O(1) ; Not considering space required by array of elements
#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int N, int *ptr)
{
    int i,j,k;
    for(i=1;i<N;i++)
    {
        for(j=i-1;j>=0;j--)
        {
            if(ptr[j]>ptr[j+1])
            {
                ptr[j]=ptr[j]-ptr[j+1];
                ptr[j+1]=ptr[j]+ptr[j+1];
                ptr[j]=ptr[j+1]-ptr[j];
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    printf("Enter no. of elements: ");
    int N;
    scanf("%d",&N);
    int *ptr=(int*)malloc(N*sizeof(int));
    printf("Enter the elements: \n");
    for(int i=0;i<N;i++)
    {
        scanf("%d",&ptr[i]);
    }
    insertion_sort(N, ptr);
    printf("\nThe sorted elements are: \n");
    for(int i=0;i<N;i++)
    {
        printf("%d ",ptr[i]);
    }
    printf("\n");
    free(ptr);
    return 0;
}