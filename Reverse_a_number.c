// Program to reverse the number
#include<stdio.h>
#include<conio.h>
void main(){
    int n,i;
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("\nThe reverese of your number is: ");
    for(int j=n;j>0;j=j/10){
        i=j%10;
        printf("%d",i);
    }
}
