#include<stdio.h>//All header files included
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 5//maximum 5 users as per the question
int queue[max]={0};//initialised queue array
int *front=-1,*rear=-1;//initialised front and rear

void Insert()//user defined function created
{
    int number;//number is taken as input from user
    printf("Enter number\n");
    scanf("%d",&number);
    if((*front==0 && *rear==max-1)||*front==*rear+1)//checking for overflow condition
        printf("Overflow\n");
    else//if queue is not overflowed then inserting element according to algorithm
    {
        if(*rear==-1)
        {*front=0;
        *rear=0;}
        else if(*rear==max-1)
            *rear=0;
        else
            (*rear)++;
        queue[*rear]=number;
        printf("Item Inserted\n");
    }
}

void Delete()//user defined function created
{
    if(*front==0)//checking for underflow condition
        printf("Underflow\n");
    else//if queue doesnt have underflow then deleting element according to algorithm
    {
        int item=queue[*front];
        queue[*front]=0;
        if(*front==*rear)
        {*front=-1;
        *rear=-1;}
        else if(*front==max-1)
            *front=0;
        else
            *(front)++;
        printf("%d Deleted\n",item);
    }
}

void Show()//user defined function created
{
    int i;
    printf("Status\n");//printing status of queue
    for(i=0;i<max;++i)
    {
        if(queue[i]==0)//if no element then blank space printed
            printf("_ ");
        else
            printf("%d ",queue[i]);//else element in array shown
    }
    printf("\n");
}

int main()
{
    label:;//label used so that we can do operation till we do not exit
    printf("----DASHBOARD-----\n");
    printf("1.Insert Elements\n");
    printf("2.Delete Elements\n");
    printf("3.Show Elements\n");
    printf("4.Exit Dashboard\n");
    int choice;//choice variable initialised
    printf("Enter choice\n");//choice entered
    scanf("%d",&choice);//switch case used for different conditions
    switch(choice)
    {
    case 1://this case is for inserting elements
    {
        Insert();//user defined function Insert used
        break;
    }
    case 2://this case is for deleting elements
    {
        Delete();//user defined function Delete used
        break;
    }
    case 3://this case is for showing status of queue
    {
        Show();//user defined function Show used
        break;
    }
    case 4://case for exiting
    {
        exit(0);
        break;
    }
    }
    goto label;//label used for doing process until we donot want to exit
}//code finished
