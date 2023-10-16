#include<stdio.h>
int main(){
    
    for(int i=1;i<=5;i++){
        int count =1;
        printf("\t\t\t");
        for(int j=1;j<=5-i;j++){
            printf("   ");
        }
        if(i==1){
            printf("1\n");
            continue;
        }
        if(i==2){
            printf("1     1\n");
            continue;
        }
        
        int ab = i-2;
        for(int k=1;k<=(i+1)/2;k++){
            
            printf("%d     ",count);
            count  = count + ab;
            ab--;
            
        }
        if(i==3){
            printf("1\n");
            continue;
        }
        int count2 = i-1; 
        for(int l=1;l<=i/2;l++){
            printf("%d     ",count2);
            count2 = count2 -(i-2);
        }
        printf("\n");
    }
    return 0;
}
