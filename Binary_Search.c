#include<stdio.h>
#include<stdlib.h>//all header files included

int Binary_Search(int arr[],int value)
{//function created for finding index of element in array
    int low=0,high,mid;
    high=(sizeof(arr)/sizeof(arr[0]));
    mid=(high+low)/2;
    while(high>low){
        if(value==arr[mid])
            return mid;
        if(value>arr[mid])
            high=mid-1;
        else
            low=mid+1;
    }return -1;
}//-1 returned if element not present

int main()
{//driver code/main function
    int size;//size of array declared and then inputed from user
    printf("Enter size of array : ");
    scanf("%d",&size);
    int a[size];//array declared and then inputed all elements
    printf("Enter the values of elements in array : \n");
    for(int i=0;i<size;++i)
        scanf("%d",&a[i]);
    int val;//value taken as input from user
    printf("Enter the value you want to search in array : ");
    scanf("%d",&val);
    int index=Binary_Search(a,val);//using function created above to find index of element
    if(index==-1)//using if else to arrive at concludion
        printf("Such element does not exist in the array\n");
    else
        printf("%d value is present at %d index of the given array\n",val,index);
}//program finished
