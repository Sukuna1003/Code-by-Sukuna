#include<stdio.h>
void Binary(int x){
    if(x==0)return ;
    int result = x%2;
    printf("%d ",result);
    Binary(x/2);
}
int main(){
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    int i=n;
    printf("Binary form of the number %d is : ",n);
    Binary(n);
}
