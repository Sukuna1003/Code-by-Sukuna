#include<stdio.h>//Including all header files
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 5//defining maximum size of 2D array
int front[max]={-1,-1,-1,-1,-1};//initialising front array
int rear[max]={-1,-1,-1,-1,-1};//initialising rear array
int pqueue[max][max];//initialising priority queue
int flag[max][max];
void Show()//creating user defined function to Show elements in priority queue
{
    printf("Displaying priority queue\n");
    for(int i=0;i<max;++i)//using nested for loops
    {
        for(int j=0;j<max;++j)
        {
            if(pqueue[i][j]==0)
                printf("_ ");//if element is 0 or not present we print a dash
            else
                printf("%d ",pqueue[i][j]);//else we show the element
        }
        printf("\n");
    }
    printf("\n");
}

void Insert(int item,int priority)//creating user defined function to insert elements
{
    if(rear[priority]==max-1)//checking overflow
    {
        printf("Overflow\n");
        return;
    }
    else//if not overflow then we Insert elements using below algorithm
    {
        if(rear[priority]==-1)
        {front[priority]=1;
        rear[priority]=1;}
        else
            rear[priority]++;
        pqueue[priority][rear[priority]]=item;
        printf("Item Inserted\n");
        flag[priority][rear[priority]]=1;
    }
}

void Delete(int item,int priority)//creating user defined function Delete to delete element
{
    if(front[priority]==0)//checking underflow
    {printf("Underflow\n");
    return;}
    else if(flag[priority][rear[priority]]==0)
    {printf("Element does not exist\n");
    return;}
    else
    {//if element is present and no underflow is there we delete using below algorithm
        int item=pqueue[priority][front[priority]];
        item=0;
        if(front[priority]==rear[priority])
        {front[priority]=0;
        rear[priority]=0;}
        else
            front[priority]++;
        printf("Item Deleted\n");
    }
}

int main()//main function called
{
    label:;//label used
    printf("---DASHBOARD---\n");
    printf("1.ENTER ELEMENTS\n");
    printf("2.DELETE ELEMENTS\n");
    printf("3.SHOW ELEMENTS\n");
    printf("4.EXIT PROGRAM\n");
    int choice;//using switch-case for different conditions
    printf("Enter the choices\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1://case1 for inserting elements
    {
        int data;//we take inputs as data and its priority
        printf("Enter data : ");
        scanf("%d",&data);
        int p;
        printf("Enter priority : ");
        scanf("%d",&p);
        Insert(data,p);//here we insert data with given priority
        break;
    }
    case 2://case2 for deleting elements
    {
        int data;//we take input of data and priority to be deleted
        printf("Enter data to be removed : ");
        scanf("%d",&data);
        int p;
        printf("Enter priority of element : ");
        scanf("%d",&p);
        Delete(data,p);//here we delete data
        break;
    }
    case 3://case3 for showing contents of priority queue
    {Show();
    break;}
    case 4:
    {exit(0);//case4 for exiting proram
    break;}
    }
    goto label;
}//program finished
