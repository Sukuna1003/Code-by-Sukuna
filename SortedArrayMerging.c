program online
#include <stdio.h>
void merge(int a[],int lena,int lenb){
    int count =0, sort[8];
    for(int i=0;i<lena;i++){
        for(int j=0;J<lenb;j++){
            if(a[i]<b[j]){
                sort[count]=a[i];
                break;
            }
            if(a[i]>b[j]){
                sort[count]=b[j];
                break;
            }
            else {
                sort[count]=a[i];
                sort[++count]=b[j];
                break;
            }
            count++;
        }
    
    }
    for(int i=0;i<(lena+lenb);i++)
       printf("%d",sort[i]);
}
int main() {
   int a[]={2,4,6,8};
   int b[]={1,3,5,7};
   int c= (sizeof(a)/sizeof(a[0]));
   int d= (sizeof(b)/sizeof(b[0]));
   merge(a,b,c,d);
    

    return 0;
}
