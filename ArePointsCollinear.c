#include<stdio.h>
int main(){
    int x[3],y[3];
    
    for(int a=1;a<=3;a++){
        printf("Enter the coordinates of your point %d: ",a);
        scanf("%d",&x[a-1]);
        scanf("%d",&y[a-1]);
    }
    for(int b=0;b<2;b++){
        if(y[b+1]==y[b] && x[b+1]==x[b]) {
            printf("Given Points are collinear.");
            return 0;

    }
    float s1 = (y[1]-y[0])/(x[1]-x[0]);
    float s2 = (y[2]-y[1])/(x[2]-x[1]);
    if(s1==s2) printf("Given points are collinear.");
    else printf("Given points are not collinear.");
    return 0;
}
}
