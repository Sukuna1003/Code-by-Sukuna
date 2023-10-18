#include<stdio.h>
int NonRecursive(int x){
    int sum=0;
    for(int i=x;i>0;i=i/10){
        sum+=i%10;
    }
    return sum;
}
int Recursive(int x){
    int sum=0;
    if(x==0) return 0;
    
    return ((x%10)+Recursive(x/10));
}
int main(){
    int n;
    printf("Enter your 5-digit number: ");
    scanf("%d",&n);
    int r=Recursive(n);
    int x=NonRecursive(n);
    printf("Sum by recursive and non recursive methods: %d, %d",r,x);
    return 0;
}
