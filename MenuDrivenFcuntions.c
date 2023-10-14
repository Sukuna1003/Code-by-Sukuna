#include<stdio.h>
#include<stdbool.h>
void fact();
void prime();
void OE();

int main(){
    int ch;
    do{

    printf("\n1. Factorial of a number. \n2. Prime or not.\n3. Odd or Even.\n4.Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    
    switch(ch){
        case 1:
            fact();
            break;
        case 2:
            prime();
            break;
        case 3:
            OE();
            break;
        case 4:
            break;
        default :
            system("cls");
            printf("Invalid choice. Please choose from above options .\n");
    }
    }while(ch!=4);
    return 0;
}
int factorial(int x){
    if(x==1 || x==0){
        return 1;
    }
    return x*factorial(x-1);
}
void fact(){
    system("cls");
    int n;
    printf("Enter your number: \n");
    scanf("%d",&n);
    printf("Factorial of your number is : %d \n",factorial(n));
}
bool Prime(int x){
    for(int i=1;i=x/2;x++){
        if(x<=1){
            return false;
        }
        if(x%i == 0){
            return false;
        }
        else 
            return true;
    }
}
void prime(){
    system("cls");
    int n;
    printf("Enter your number: ");
    scanf("%d",&n);
    if(Prime(n)){
        printf("It is a prime number.\n");
    }
    else 
        printf("It is not a prime number.\n");
}
int OddOrEven(int x){
    if(x%2==0){
        return 1;
    }
    else return 0;
}
void OE(){
    system("cls");
    int n;
    printf("Enter your number: ");
    scanf("%d",&n);
    if(OddOrEven(n))
        printf("Your number is Even\n");
    else printf("Your number is Odd\n");

}


