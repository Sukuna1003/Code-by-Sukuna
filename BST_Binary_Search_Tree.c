#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//all header files included
struct BST{
    struct BST *lchild;
    char name[20];
    long long phone_no;
    struct BST *rchild;
};//self referncial structure for constructing binary search tree(bst)
struct BST *root=NULL;
//rootnode initialised as null

struct BST* Create_Node(char str[],long long x)
{//function for creating a node of bst
    struct BST *ptr;//initialising pointer and allocationg memory
    ptr=(struct BST*)malloc(sizeof(struct BST));
    strcpy(ptr->name,str);
    ptr->phone_no=x;
    ptr->lchild=NULL;//doing required pointer settings
    ptr->rchild=NULL;
    return ptr;}//returning pointer

void Search(char s[],long long n)
{//function for inserting elements into bst
    int ct=0,flag=0;//variables initialised
    struct BST *t1,*t2;//two temporary pointers created
    t1=root;//t1 set to root
    while(t1!=NULL && flag==0)
    {//using while loop to search for node
        ct++;
        if(strcmp(t1->name,s)==0 && t1->phone_no==n)
            flag=1;//flag=1 means entry found in bst
        else if(strcmp(s,t1->name)<=0 || (strcmp(s,t1->name)>0 && t1->phone_no>n))
        {//using if else com=nditions to search for entry if not found before
            t2=t1;
            t1=t1->lchild;}
        else{
            t2=t1;
            t1=t1->rchild;}
    }if(flag==0)//if flag is still 0 means eelement not found in bst
        printf("Entry not present in phonebook\n");
    else
        printf("Given Entry found at %d search",ct);}

void Insert(char s[],long long n)
{//function to insert entry into bst
    struct BST *new_node=Create_Node(s,n);
    if(root==NULL)
    {//checking using if conditions
        root=new_node;
        printf("Entry Inserted in phonebook");
        return;
    }//if root not null follow below algorithm
    struct BST *t1,*t2;
    t1=root;
    while(t1!=NULL)
    {
        if(strcmp(s,t1->name)<=0 || (strcmp(s,t1->name)>0 && t1->phone_no>n)){
            t2=t1;
            t1=t1->lchild;
        }else{
            t2=t1;
            t1=t1->rchild;}
    }//if we reach a node whose child is null then we can insert entry
    if(strcmp(s,t2->name)<=0 || (strcmp(s,t2->name)>0 && t2->phone_no<n))
        t2->lchild=new_node;
    else//using if else to enter node in bst
        t2->rchild=new_node;
    printf("Given Entry Inserted in phone book");}

struct BST* Inorder_Predesor(struct BST *node)
{//function to find inorder predesecor of given node in bst
    while(node->rchild!=NULL)
        node=node->rchild;//using while loops to find required node
    return node;
}//returning node after finding it

struct BST* Delete(struct BST *root,char str[],long long x)
{//function to delete a entry from bst
    if(root==NULL)//using if else control statements
        return root;
    if(strcmp(root->name,str)>0)
        root->lchild=Delete(root->lchild,str,x);
    else if(strcmp(root->name,str)<0)
        root->rchild=Delete(root->rchild,str,x);
    else{
        if(root->lchild==NULL){
            struct BST *t=root->rchild;
            free(root);
            return t;
        }else if(root->rchild==NULL){
            struct BST *t=root->lchild;
            free(root);
            return t;}
        struct BST *t=Inorder_Predesor(root->lchild);
        strcpy(root->name,t->name);
        t->phone_no=root->phone_no;
        root->lchild=Delete(root->lchild,t->name,t->phone_no);
    }//use above algorithm to delete given node
    printf("Given Entry is now Deleted\n");
    return root;
}//returning root node after doing required operations

void Increasing_Order(struct BST *node)
{//function to print entries in lexographic order
    if(node!=NULL)
    {//since this is bst we can print inorder traversal sequence
        Increasing_Order(node->lchild);
        printf("%s %lld\n",node->name,node->phone_no);
        Increasing_Order(node->rchild);}
}//this produces entries in lexographic order

void Decreasing_Order(struct BST *node)
{//function to print entries in decreasing order
    if(node!=NULL)
    {//since this is bst use below algorithm
        Decreasing_Order(node->rchild);
        printf("%s %lld\n",node->name,node->phone_no);
        Decreasing_Order(node->lchild);}
}//this function will thus print entries in decreasing order

int main()
{//main function/driver code
    while(1)
    {//using infinite loop
        printf("---PHONEBOOK---\n");//menu or dashboard created
        printf("1.INSERT ENTRY IN PHONEBOOK\n");
        printf("2.DELETE ENTRY FROM PHONEBOOK\n");
        printf("3.SEARCH FOR ENTRY IN PHONEBOOK\n");
        printf("4.PRINT ALL ENTRIES IN INCREASING ORDER\n");
        printf("5.PRINT ALL ENTRIES IN DECREASING ORDER\n");
        int choice;//choice taken as input from user
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {//using switch case statements
        case 1:
            {//this case is for inserting entry in bst
                char s[20];
                long long n;
                printf("Enter details of entry to be inserted in phonebook : ");
                scanf("%s %lld",s,&n);
                Insert(s,n);
                printf("\n");
                break;}
        case 2:
            {//this case is for deleting entry from bst
                char s[20];
                long long n;
                printf("Enter details of entry to be deleted from phonebook : ");
                scanf("%s %lld",s,&n);
                struct BST *ptr=Delete(root,s,n);
                printf("\n");
                break;}
        case 3:
            {//this case is for searching a particular entry provided by user
                char s[20];
                long long n;
                printf("Enter details of entry to be searched in phonebook : ");
                scanf("%s %lld",s,&n);
                Search(s,n);
                printf("\n");
                break;}
        case 4:
            {//this case is for printing entries in increasing order
                printf("The entries of phonebook in Increasing order are : \n");
                Increasing_Order(root);
                break;}
        case 5:
            {//this entry is for printing entries in decreasing order
                printf("The entries of phonebook in Decreasing order are : \n");
                Decreasing_Order(root);
                break;}
        default:
            {//default case other than above mentioned cases
                exit(0);
                break;}
        }//this case breaks the while loop
    }//code finished
}//after this output will be displayed
