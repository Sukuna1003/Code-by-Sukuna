#include <stdio.h>//All header files included
#include<stdlib.h>
#include<string.h>
#define max 1001//defining max size of stack globally
char stack[max];//globally declaring char array of stack(LIFO data structure)
int top;//globally declaring top variable
void push(char x)//declaring push function to push variable into stack
{
    if(top==max-1)//stack overflow condition defined
    {printf("Stack overflow\n");}
    else
    {stack[++top]=x;}//assigning character value to stack at index top
}

char pop()//declaring pop function to pop variable from stack
{
    if(top==0)//stack undeflow condition defined
    {printf("Underflow\n");}
    else
    {
        char x;//returning character at top position
        x=stack[top--];
        return x;
    }
}

int main()//main called
{
    int i;
    char s[101];//initialising string
    printf("Enter the input\n : ");
    gets(s);//inputing string
    for(i=0;i<strlen(s);++i)
    {push(s[i]);}//pushing characters of string into stack
    printf("\nThe output is : ");
    for(i=0;i<strlen(s);++i)//outputing characters
    {
        char temp=pop();//since stack is LIFO data structure characters are printed in reverse order
        printf("%c",temp);
    }
    return 0;//code finished
}
