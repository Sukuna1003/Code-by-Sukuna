#include<stdio.h>
int main(){
    int age, health, sex, place;
    printf("Enter 1 if your health is Excellent\nEnter 2 if your health is poor: \n");
    scanf("%d",&health);
    if(health !=1 || health != 2){
         printf("Your are not eligible for our policy. ThankYou!");
         return 0;
    }
    printf("Enter your age: ");
    scanf("%d",&age);
    if(age<25 || age>35){
        printf("Your are not eligible for our policy. ThankYou!");
        return 0;
    }
    
    printf("Enter your sex.\nPress 1 for male\nPress 2 for female: ");
    scanf("%d",&sex);
    if(sex!=1 || sex !=2){
         printf("Your are not eligible for our policy. ThankYou!");
         return 0;
    }
    printf("Enter the place where you live\nIf you live in city, press 1\nIf you live in village, press2");
    scanf("%d",&place);
    if( place!=1 || place!=2){
         printf("Your are not eligible for our policy. ThankYou!");
         return 0;
    }
    if(35>=age>=25 && health==1 && place==1 && sex == 1){
        printf("Your premium is of Rs.4 pre thousand and your maximum policy amount is Rs.2Lakhs only.");
    }
    if(35>=age>=25 && health==1 && place==1 && sex == 2){
        printf("Your premium is of Rs.3 pre thousand and your maximum policy amount is Rs.1Lakhs only.");
    }
    if(35>=age>=25 && health==2 && place==1 && sex == 1){
        printf("Your premium is of Rs.6 pre thousand and your maximum policy amount is Rs.10,000 only.");
    }
    else printf("Your are not eligible for our policy. ThankYou!");
    
}
