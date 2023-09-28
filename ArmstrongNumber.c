// Program to print the Armstrong numbers between 0 to 2000.
#include<stdio.h>
int main(){
    int n,a[5];
    printf("Armstrong number between 0 to 100 are: ");
    for(n=1;n<2000;n++){
        int nod=0,sum=0;
        int j=0;
        for(int i=n;i>0;i=i/10){
            int digit ;
            digit = i%10;
            a[j] = digit;
            j++;
            nod++;
        }
        
            for(int j=0;j<nod;j++){
                
               
                for(int k=0;k<nod;k++){
                    a[j] = a[j]*a[j];
                }
            }
        for(int i=0;i<nod;i++)
            sum=sum+a[i];
        if(n==sum)
            printf("%d\n",n);
        
    }
    return 0;
}
