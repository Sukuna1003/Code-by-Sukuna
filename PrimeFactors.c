#include<stdio.h>
int  Recursive(int x){
    int i;
    if(x=1) return 1;
    for( i=2;i*i<=x;i++){
        if(x ==0) return 1;
        if(x%i==0 && isPrime(i)==1){
            printf("%d %d ",i,Recursive(x/i));
        }
    }
    return Recursive(x/i);
}
int isPrime(int x){
    int i;

    if(x<=1)return 0;

    for(i=2;i*i<=x;i++){
        if(x%i==0)break;
    }

    if(i*i>x)return 1;

    return 0;
}
int main(){
    int n,i,j;

    printf("Enter the number: ");
    scanf("%d",&n);

    if(n==1)printf("1");
    if(n==2)printf("1 2");
    if(n<=0)printf("Invalid Input");  

    for(i=1;i*i<=n;i++){
        if((n%i==0)&&isPrime(i)==1){
            printf("%d ",i);
        } 
    }
    
    if(i*i>n){
        printf("\nNo factors found");
    }

    Recursive(n);
    return 0;
}

 /*if(isPrime(i)==0) continue;
        if(n%i==0){
            printf("%d ",i);
        }*/
