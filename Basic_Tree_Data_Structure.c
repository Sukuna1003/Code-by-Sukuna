#include<stdio.h>
#include<stdlib.h>//All header files included

struct Tree
{
    struct Tree *leftchild;
    int data;
    struct Tree *rightchild;
};//self referencial structure for Tree
struct Tree *root=NULL;//Root node initialised as NULL

struct Tree* Create_Node(int info)
{//Function for creating new node of a tree
    struct Tree *new_node;//initialising Tree and allocating memory
    new_node=(struct Tree*)malloc(sizeof(struct Tree));
    new_node->data=info;//data of node made as data given
    new_node->leftchild=new_node->rightchild=NULL;
    return new_node;//doing modifications and returning node
}//global variable declared as 0

int preorder_ct=0;
struct Tree* Create_Tree(int a[],int b[],int start,int end)
{//Function for creating tree from arrays,start index and end index
    if(start>end)//Using appropriate Function and algorithm for creating tree
        return NULL;
    struct Tree *new_node=Create_Node(a[preorder_ct++]);
    if(start==end)
        return new_node;
    int in_ct;
    for(int i=start;i<end;++i)
    {
        if(new_node->data==b[i])
            in_ct=i;
    }//using recursion for left and right child of Tree
    new_node->leftchild=Create_Tree(a,b,start,in_ct-1);
    new_node->rightchild=Create_Tree(a,b,in_ct+1,end);
    return new_node;
}//returning node after doing modifications

void preorder_traversal(struct Tree *node)
{//Function for preorder traversal in a constructed Tree
    if(node!=NULL)
    {//if root node is not null then
        printf("%d ",node->data);//first printing data of node
        preorder_traversal(node->leftchild);//Function call for left child
        preorder_traversal(node->rightchild);//Function call for right child
} }//recursion used as function calls itself

void inorder_traversal(struct Tree *node)
{//Function for inorder Traversal in a constructed Tree
    if(node!=NULL)
    {//if root node is not NULL
        inorder_traversal(node->leftchild);//Function call for left child
        printf("%d ",node->data);//then printing data of node
        inorder_traversal(node->rightchild);//Function call for right child
    }//recursion is used as function calls itself
}

int main()//driver code
{//main function called
    int n;//declaring size of arrays
    printf("Enter size of arrays : ");
    scanf("%d",&n);//taking input of size from user
    int pre_order[n],in_order[n];//initialising preorder and inorder arrays
    printf("Enter preorder Traversed Tree Elements : \n");
    for(int i=0;i<n;++i)//using for loop and taking inputs from user
        scanf("%d",&pre_order[i]);
    printf("Enter inorder Traversed Tree Elements : \n");
    for(int i=0;i<n;++i)//using for loop and taking inputs from user
        scanf("%d",&in_order[i]);
//creating root node of tree using Function Create_Tree
    struct Tree *root=Create_Tree(pre_order,in_order,0,n-1);
//Function Create_Tree called to Construct Tree from given preorder and inorder traversal arrays
    printf("Printing Postorder Traversal : \n");
    preorder_traversal(root);
//Function preorder_traversal used to traverse through entire tree and print elements in that order
    printf("\nPrinting inorder Traversal : \n");
    inorder_traversal(root);
//Function inorder_traversal used to traverse through entire tree and print elements in that order
    return 0;}
