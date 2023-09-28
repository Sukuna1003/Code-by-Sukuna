#include<stdio.h>
int main(){
    char ch;
    printf("Press any Key: ");
    scanf("%c",&ch);
    int x = ch;
    if(x>=65 && x<=90)printf("The character is a capital letter.");
    else if(x>=97 && x<=122)printf("The character is a small letter.");
    else if(x>=48 && x<=57)printf("The character is a digit.");
    else if(x>=0 && x<=47 || x>=58 && x<=64 || x>=91 && x<=96 || x>=123 && x<=127)printf("The character is a Special Symbol.");
    return 0;
}
