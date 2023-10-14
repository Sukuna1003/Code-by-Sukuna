#include<stdio.h>
void merg(int a[] ,int alength, int b[],int blength);
int main(){
    int arr1[] = {2,4,6,8};
    int arr2[] = {1,3,5,7};
    int larr1 = (sizeof(arr1)/sizeof(arr1[0]));
    int larr2 = (sizeof(arr2)/sizeof(arr2[0]));
    // int a = larr1+larr2;
    merg(arr1,larr1,arr2,larr2);
  
}

void merg(int a[],int alength, int b[],int blength){
    int sorted[40];
    int count=0;
    int i=0,j=0;
    while( i<alength && j<blength){
        if(a[i]<b[j]){
            sorted[count++] = a[i++];
        }
        else{
            sorted[count++] = b[j++];
        }
    }
    if(i==alength){
        for(j;j<blength;j++){
            sorted[count++] = b[j];
        }
    }
    if(j==blength){
        for(i;i<alength;i++){
            sorted[count++] = a[i];
        }
    }
    for(int i=0;i<count;i++)
        printf("%d ",sorted[i]);
    return ;
}
