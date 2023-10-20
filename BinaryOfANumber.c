#include<stdio.h>
int main(){
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    int i=n;
    printf("Binary form of the number %d is : ",n);

    while(i>0){
        int binary = i%2;
        printf("%d ",binary);
        i/=2;
    }
    
}
