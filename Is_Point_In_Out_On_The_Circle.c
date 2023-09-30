#include<stdio.h>
int cPower(int x, int y){
    int result = 1;
    if(y==0) return 1;
    for(int i=0;i<y;i++){  
        result*=x;
    }
    return result;
}
int main(){
    int r,a,b,x,y;
    printf("Enter the Center of the circle: \n");
    scanf("%d %d",&a,&b);
    printf("Enter the radius of the circle: \n");
    scanf("%d",r);
    printf("Enter the coordinates of your point: \n");
    scanf("%d%d",&x,&y);
    int length  = cPower(x-a,2)+cPower(y-b,2);
    if(length==r)printf("Point is on the circumfrence of the circle.");
    else if(length>r)printf("Point is outside of the circle.");
    else if(length<r)printf("Point is inside of the circle.");
    printf("%d",length);
    return 0;
}
