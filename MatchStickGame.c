#include<stdio.h>
int main(){
    int SC=0,SU=0;
    int Q;
    printf("Rules:\nThere are 21 matchsticks.\nThe computer will ask you to pick 1,2,3 or 4 matchsticks.\nAfter you pick the computer will do the picking.\nWhoever is forced to pick the last matchstick will lose the game.\n");
    printf("\t\t\t\t=============================================================\n");
    printf("\t\t\t\t=============================================================\n");
    printf("\n\t\t\t\t\t\t****START****\n");
    do{
        int m=21,n,j;
        while(m>1){
        printf("There are %d matchsticks left. Pick 1, 2, 3 or 4 : ",m);
        scanf("%d",&n);

        if(n<1 || n>4 || n>m){
            printf("Invalid Choice!!!, please pick the correct choice.\n");
            continue;
        }

        m-=n;
        printf("User picked %d matchsticks. %d mathcsticks are remaining: \n",n,m);
        j = 5-n;
        m-=j;
        printf("Computer picked %d matchsticks. %d matchsticks are remaining.\n",j,m);
        }

        if(m==1){
            printf("You are forced to pick up the last matchstick. Computer wins....\n");SC++;
        }
        else {
            printf("Computer is forced to pick up the last mathcstick. You win....\n");SU++
        ;}
        printf("Do you want to play another game?\n  Press '1' if yes and '0' if no: \n");
        scanf("%d",&Q);
        if(Q!=1 || Q!=0)
            printf("Please enter the correct key.");

    }while(Q !=0);
    printf("\t\t\t===========Game Ends Here=============\n");
    printf("Score Board:\nComputer Won %d times.\nAnd\nUser Won %d times",SC,SU);
    return 0;
}
