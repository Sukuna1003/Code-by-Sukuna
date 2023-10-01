#include<stdio.h>
char a[]={'1','2','3','4','5','6','7','8','9'};

void board();
int checkwin();
int main(){
    int player = 1,i=-1,choice;
    
    do{

        board();
        
        player = (player%2)? 1  :2 ;
        printf("Player %d enter your choice: ",player);
        scanf("%d",&choice);
        if(1>choice>9){
            continue;
        }
        
        char move = (player == 1)? 'X' : 'O';

        if(a[choice-1] != 'X' && a[choice-1]!= 'O')
            a[choice-1] = move;
        else {
            printf("Invalid Choice...");
            continue;
        }

        player++;
        i=checkwin();

    }while(i == -1);

    if(i==1){
       printf("****PLayer %d wins..****",--player);
    }
    
    else {
        board();
        printf("**** Game Draws ****");

    }

}

int checkwin(){
    if((a[0]==a[1]==a[2]) || (a[3]==a[4]==a[5]) || (a[6]==a[7]==a[8]) || (a[0]==a[3]==a[6]) || (a[1]==a[4]==a[7]) ||
     (a[2]==a[5]==a[8]) || (a[0]==a[4]==a[8]) || (a[2]==a[4]==a[6]))
        return 1;
        else if (a[0] != '1' && a[1] != '2' && a[2] != '3' &&
               a[3] != '4' && a[4] != '5' && a[5] != '6' &&
               a[6] != '7' && a[7] != '8' && a[8] != '9') {
        return 0; 
    }

    else return -1;
}

void board(){
    system("cls");
    printf("\t\t\tTIC TAC TOE Game\n");
    printf("\t\tPlayer 1: (X) and Player 2: (O) \n");
    printf("\t\t\t     |     |     \n");
    printf("\t\t\t  %c  |  %c  |  %c  \n",a[0],a[1],a[2]);
    printf("\t\t\t_____|_____|_____\n");
    printf("\t\t\t     |     |     \n");
    printf("\t\t\t  %c  |  %c  |  %c  \n",a[3],a[4],a[5]);
    printf("\t\t\t_____|_____|_____\n");
    printf("\t\t\t     |     |     \n");
    printf("\t\t\t  %c  |  %c  |  %c  \n",a[6],a[7],a[8]);
    printf("\t\t\t     |     |     \n\n");

    

}
