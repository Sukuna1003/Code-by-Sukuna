#include<stdio.h>//header files included
#include<stdlib.h>

struct node{//linked list creation using structure
    int data;
    struct node *next;
};
struct node *start=NULL;//start pointer given as null
int ct=0;//counter to count number of elemeents in list

void Ins_Beg(int x)//function to insert elementat beginnning of list
{
    ct++;
    struct node *new_node;//new node created
    struct node *t;//temporary node created for traverse throughout list
    new_node=(struct node*)malloc(sizeof(struct node));//new node stored
    t=start;//pointer of first saved in t
    new_node->data=x;
    if(start==NULL)//main algorithm for insertion at begenning
    {
        start=new_node;
        new_node->next=NULL;
    }
    else
    {
        start=new_node;
        t=t->next;
        new_node->next=t;
    }
}

void Ins_End(int x)//function to insert element at end of list
{ct++;
struct node *new_node;//creating new node
struct node *t;//temporary node created for traverse throughout list
new_node=(struct node*)malloc(sizeof(struct node));//new node stored
new_node->data=x;
t=start;//pointer of first saved in t
while(t->next!=NULL)//main insertion for algoritm at the end
     t=t->next;
t->next=new_node;
new_node->next=NULL;
}

void Ins_middle(int x,int position)//function for inserting element according to position
{
    ct++;
    struct node *new_node;//new node created
    struct node *t;//temporary pointers created
    struct node *temp;
    new_node=(struct node*)malloc(sizeof(struct node));//new node stored
    new_node->data=x;
    t=start;
    if(position==1)
    	Ins_Beg(x);
    else if(position==ct+1)
    	Ins_End(x);
    else if(position<0 || position>ct+1)
    	printf("Element cannot be Inserted\n");
    else{
    for(int i=1;i<position;++i)//first we go to position where insertion will be done
    {
    	temp=t;//t stored in temp
    	t=t->next;//then traversing using t
    }
    temp->next=new_node;
    new_node->next=t;}
}

void Del_beg()//function to delete node at begenning
{
    struct node *t;//temporary node called
    if(start==NULL)
    {printf("Underflow\n");//checking for underflow
    return;}
    t=start;//start stored in t
    int x=t->data;//element stored in another variable
    start=t->next;//then deleted acc. to algorithm
    free(t);//we make pointer free from memory
}

void Del_middle(int position)//deletion function at given position
{
    if(start==NULL)//check for underflow
    {printf("Overflow\n");
    return;}
    struct node *t;//temporary pointers created
    struct node *temp;
    t=start;//start pointer stored in t
    for(int i=0;i<=position;++i)
    {
    	temp=t;//t pointer stored in temp
    	t=t->next;//then traversing using t for going to given position
    }
    int x=t->data;//data of node stored in other variable
    temp=t->next;//then deleting that element from node using algorithm
    free(t);//we free pointers from memory
    free(temp);
}

void Del_end()//deletion function at end position
{
    if(start==NULL)//check for underflow
    {printf("Underflow\n");
    return;}
    struct node *t;//temporary pointers created
    struct node *temp;
    t=start;//start pointer stored in t
    while(t->next!=NULL)
    {
        temp=t;//t stored in temp
        t=t->next;//then t used for traversing to find last node
    }
    int x=t->data;//last node data stored in other variables
    temp=t->next;//then deleting that data
    free(t);//we free pointers from memory
    free(temp);
}

void Search(int x)//searching for particular element in list
{
    int pos=0;//position that helps in finding position of search element
    if(start==NULL)//check for empty list
    {printf("No element present in list\n");
    return;}
    struct node *t;//temporary pointer created
    t=start;//start pointer stored in t
    while(t->next!=NULL)//then traverse in list till we reach last node
    {
    	pos++;//incrementing position to know position of element in list
    	if(t->data==x)//if element found at first position
    	{printf("Element found at %d position\n",pos);
    	return;}
    	t=t->next;//else traversing in list
    }
    if(t->next==NULL)//if element not found till last node
    {
    	if(t->data==x)//check whether searched element is data of last node?
    	{printf("Element found at last position\n");}
    	else//else element absent in list
    	{printf("Element not present in the list\n");}
    }
}

void Transverse()//function for traversing and printing all elements of list
{
    printf("The number of elements are %d\n",ct);
    struct node *t;//create temporary pointer
    //t=(struct node*)malloc(sizeof(struct node));
    t=start;//start pointer stored in t
    while(t!=NULL)//traversing till we reach null pointer
    {
        printf("%d ",t->data);//printing elements
        t=t->next;//reaching next element
    }
    printf("\n");
}

int main()//driver code/main function
{
  while(1)//using infinite while loop
  {
    printf("----Dashboard----\n");//printing dashboard
    printf("1.Insert at begenning\n");
    printf("2.Insert at Middle\n");
    printf("3.Insert at end\n");
    printf("4.Delete from begenning\n");
    printf("5.Delete from Middle\n");
    printf("6.Delte from End\n");
    printf("7.Linked list Transversal\n");
    printf("8.Search element in the list\n");
    printf("9.Exit\n");
    int choice;//using choice with switch case
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
    {printf("Enter the element to insert : ");//insertion at begenning
    int num;
    scanf("%d",&num);
    Ins_Beg(num);
    printf("Element Inserted\n");
    break;}
    case 2://insertion at middle
    {printf("Enter the element to insert : ");
    int num,ind;
    scanf("%d",&num);
    printf("Enter position of element to insert : ");
    scanf("%d",&ind);
    Ins_middle(num,ind);
    printf("Element inserted in middle\n");
    break;}
    case 3://insertion at end
    {printf("Enter the element to insert : ");
    int num;
    scanf("%d",&num);
    Ins_End(num);
    printf("Element inserted at the end\n");
    break;}
    case 4://deletion at begenning
    {Del_beg();
    printf("Element deleted from the begenning\n");
    break;}
    case 5://deletion at specific position
    {int ind;
    printf("Enter position of deletion : ");
    scanf("%d",&ind);
    Del_middle(ind);
    printf("Element deleted from the given position\n");
    break;}
    case 6://deletion at end
    {Del_end();
    printf("Element deleted from the end\n");
    break;}
    case 7://traversing and printing list
    {printf("Linked list transversal\n");
    Transverse();
    break;}
    case 8://searching element
    {int num;
    printf("Enter element to be searched : ");
    scanf("%d",&num);
    Search(num);
    break;}
    case 9://exiting and breaking the loop
    {exit(0);
    break;}
    }
  }
}
