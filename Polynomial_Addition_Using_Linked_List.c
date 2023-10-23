#include<stdio.h>
#include<stdlib.h>//all header files included
struct poly{//linked list created using structure
    int px;
    int py;
    int pz;//powers of x,y,z
    int coeff;//members of structures
    struct poly*next;//self referencial structure pointing to next node
};
struct poly*poly1=NULL;//one polynomial created
struct poly*poly2=NULL;//second polynomial created
struct poly*poly3=NULL;//third polynomial created
//for storing sum of previous 2 polynomials
struct poly* p_insert(int x,int y,int z,int c,struct poly*p)//function created for insertion
{struct poly*new_node=(struct poly*)malloc(sizeof(struct poly));
    new_node->px=x;
    new_node->py=y;
    new_node->pz=z;
    new_node->coeff=c;
    new_node->next=NULL;
    if(p==NULL){//inserting elements according to algorithm
        p=new_node;
        return p;
    }
    struct poly*ptr=p;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=new_node;
    return p;}
void show(struct poly* p)//function created for displaying polynomial
{if(p==NULL){//showing terms of polynomial using this algorithm
        printf("Polynomial is Empty!\n");
        return;
    }
    struct poly*head=p;
    while(head!=NULL){
        printf("%d(x^%d)(y^%d)(z^%d)",head->coeff,head->px,head->py,head->pz);
        if(head->next!=NULL){
            printf(" + ");
        }
        head=head->next;
    }
}
struct poly* poly_add(struct poly*p1,struct poly*p2)//function created
{struct poly*to_p1=p1;//for adding two polynomials
    struct poly*to_p2=p2;
    struct poly*sum=NULL;
    while(p1!=NULL && p2!=NULL){//using algorithm for finding sum of all terms
        if((p1->px==p2->px) && (p1->py==p2->py) && (p1->pz==p2->pz)){
            if(p1->coeff+p2->coeff!=0){
                sum=p_insert(p1->px,p1->py,p1->pz,p1->coeff+p2->coeff,sum);
                p1=p1->next;
                p2=p2->next;
            }
            else if(p1->coeff+p2->coeff==0){
                p1=p1->next;
                p2=p2->next;
                continue;
            }
        }
        else if(((p1->px>p2->px) || (p1->px==p2->px)) && ((p1->py>p2->py) || (p1->py==p2->py)) && ((p1->pz>p2->pz) || (p1->pz==p2->pz))){
            sum=p_insert(p1->px,p1->py,p1->pz,p1->coeff,sum);
            p1=p1->next;
        }
        else{
            sum=p_insert(p2->px,p2->py,p2->pz,p2->coeff,sum);
            p2=p2->next;
        }
    }
    struct poly*last_sum=sum;
    while(last_sum->next!=NULL)
    {last_sum=last_sum->next;}
    if(p1!=NULL)
    {last_sum->next=p1;}
    else if(p2!=NULL)
    {last_sum->next=p2;}
    p1=to_p1;
    p2=to_p2;
    return sum;}
int main(){//main function called
    int x,y,z,c;
    //Reading Terms of First Polynomial
    printf("Enter Coeff, Power of x,y,z for Poly 1:\n");
    scanf("%d %d %d %d",&c,&x,&y,&z);
    while(c!=0){
        poly1=p_insert(x,y,z,c,poly1);
        printf("Enter Coeff, Power of x,y,z for Poly 1:\n");
        scanf("%d %d %d %d",&c,&x,&y,&z);}
    //Reading Terms of second Polynomial
    printf("Enter Coeff, Power of x,y,z for Poly 2: \n");
    scanf("%d %d %d %d",&c,&x,&y,&z);
    while(c!=0){
        poly2=p_insert(x,y,z,c,poly2);
        printf("Enter Coeff, Power of x,y,z for Poly 2:\n");
        scanf("%d %d %d %d",&c,&x,&y,&z);}
    //Displaying all three polynomials
    printf("\n");
    printf("\nFirst Polynomial:\n");
    show(poly1);
    printf("\n");
    printf("\nSecond Polynomial:\n");
    show(poly2);
    //Adding Polynomials
    poly3=poly_add(poly1,poly2);
    printf("\n");
    printf("\nMain Polynomial: (Sum of both)\n");
    show(poly3);
    printf("\n");
return 0;}
