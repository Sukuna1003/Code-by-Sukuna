#include<stdio.h>
int main(){
    int sum=0,i=1,n;
    do{
        printf("Enter number %d: ",i);
        scanf("%d",&n);

        sum = sum+i;
        
    }while (i<=10);
    printf("Sum of your numbers is: %d",sum);
    return 0;
}
