// Program to print another form of triangle.
#include<stdio.h>
int main(){
    int n,i,j,k;
    printf("Enter the size of your triangle: ");
    scanf("%d",&n);
    for(int x=1;x<=n;x++){
        printf("\t");
    }
    for(i=1;i<=n;i++){
        for(int s=n-i;s>0;s=s-1)
            printf(" ");
        for(j=i;j>1;j--)
                printf("%d",j);
        
        for(k=1;k<=i;k++)
            printf("%d",k);
        printf("\n");
    }
    
}
