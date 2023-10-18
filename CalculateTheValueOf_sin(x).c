#include<stdio.h>
int fact(int x){
    if(x==0||x==1) return 1;
    return x*fact(x-1);
}
int pow(int x,int y){
    int result=1;
    for(int i=0;i<y;i++){
        result *= x;
    }
    return result;
}

int main(){
    int x;
    double ans=0;
    printf("Enter the number: ");
    scanf("%d",&x);
    for(int i=1;i<=4;i++){
        if(i%2!=0){
            ans+=pow(x,i+i-1)/(fact(i+i-1));
        }
        else ans-=pow(x,i+i-1)/(fact(i+i-1));
    }
    printf("%lf",ans);
}
