#include <stdio.h>
#include<stdlib.h>
// function to swap the the position of two elements
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int Selection_Sort(int array[],int size_Array)
{
    for(int i=0;i<size_Array;++i)
    {
        int min=i;
        for(int j=i+1;j<size_Array;++j)
        {
            if(array[min]>array[j])
                min=j;
        }
        if(min!=i)
            swap(array[i],array[min]);
    }
}

// driver code
int main()
{
    int n;
    int a[n];
    printf("Enter size of array : ");
    scanf("%d",&n);
    printf("Enter Elements of array : \n");
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    selectionSort(a,n);
    printf("Sorted array in Acsending Order:\n");
    for(int i=0;i<n;++i)
        printf("%d ",a[i]);
    return 0;
}
