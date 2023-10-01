#include<stdio.h>

char array[] = {'1','2','3','4','5','6','7','8','9'};
int win[8] = {7, 56, 73, 84, 146, 273, 292, 448};


void setCell(int* player, int cell){
    *player |= (1 << cell);
}


void board();
int checkwin(int x);


int main(){

    int player1 = 0;
    int player2 = 0;
    int Player=1,choice,i=0;

     while(i<9){
        board();
        Player = (Player%2)?1:2;
        int* A = (Player==1)?&player1 : &player2;
        char mark;
        printf("Player %d enter your choice: ",Player);
        scanf("%d",&choice);
        mark = (Player==1)?'X':'O';
        if(choice>=1 && choice<=9 && array[choice-1]!='X' && array[choice-1]!='O'){
            array[choice-1] = mark;
            setCell(A,choice-1);
        }
        else{
            continue;
        }
        
        
        if(checkwin(*A)==1){
            break;
        }
        Player++;
        i++;
        
    }


    board();
    if(i==9){
        printf("**** Game Draws ****");
    }
    else 
        printf("Player %d wins....",Player);
    return 0;
        
}


int checkwin(int x){
    for(int j=0;j<8;j++){
            if((x&win[j])==win[j]){
                return 1;
            }
        
    }
    return 0;
}


void board(){
    system("cls");
    printf("\t\t\tTIC TAC TOE Game\n");
    printf("\t\tPlayer 1: (X) and Player 2: (O) \n");
    printf("\t\t\t     |     |     \n");
    printf("\t\t\t  %c  |  %c  |  %c  \n",array[0],array[1],array[2]);
    printf("\t\t\t_____|_____|_____\n");
    printf("\t\t\t     |     |     \n");
    printf("\t\t\t  %c  |  %c  |  %c  \n",array[3],array[4],array[5]);
    printf("\t\t\t_____|_____|_____\n");
    printf("\t\t\t     |     |     \n");
    printf("\t\t\t  %c  |  %c  |  %c  \n",array[6],array[7],array[8]);
    printf("\t\t\t     |     |     \n\n");

}

