#include<stdio.h>//All header files included
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct Employ{//structure employ is created
    char name[256];//name is stored
    int age;//age is stored
    int exists;//exists means whether employ detail is in record or not
};

int main()
{//main function called
    int number_of_employees=0,id,MAX_EMPLOYEES;//initialising all variables
    printf("Enter maximum number of employees: ");
    scanf("%d",&MAX_EMPLOYEES);//entering number of employees
    struct Employ* emp;//structure employ created and stored using dynamic memory allocation
    emp=(struct Employ*)malloc(MAX_EMPLOYEES*sizeof(struct Employ));
    for(int i=0;i<MAX_EMPLOYEES;++i)//initially no record of employees is there
    {emp[i].exists=0;}
    while(1){//using infinite while loop
        printf("====================\n");
        printf("Select an option:\n");
        printf("[1]add employee\n");
        printf("[2]remove employee\n");
        printf("[3]find employee\n");
        printf("[4]list employees\n");
        printf("[5]exit\n");
        printf("====================\n");
        int choice;//giving options to user
        scanf("%d",&choice);
        switch(choice){//using switch-case statements
            case 1://here details of employees are added
                printf("enter id of employee:");
                scanf("%d",&id);
                printf("enter name of employee:");
                scanf("%s",emp[id].name);
                printf("enter age of employee:");
                scanf("%d",&emp[id].age);
                emp[id].exists=1;
            printf("====================\n");
            break;
            case 2://here details of employees can be removed from record if their record exists
                printf("enter id of employee:");
                scanf("%d",&id);
                emp[id].exists=0;
                if(emp[id].exists)
                    printf("\nAccount not removed");
                else
                    printf("\nAccount Succesfully removed\n");
            printf("====================\n");
            break;
            case 3://here you can find details of employee indivisually by entering id
                printf("enter id of employee:");
                scanf("%d",&id);
                if(emp[id].exists)
                {//if record of employee exists it will output the employee
                    printf("Name: %s\n",emp[id].name);//details for that particular id
                    printf("Age: %d\n",emp[id].age);
                }
                else
                    printf("Employee not found\n");
                printf("====================\n");
            break;
            case 4://here you can print details of all employees that are in record in a tabular/list format
            printf("ID          NAME            AGE\n");
                for(int i=0;i<MAX_EMPLOYEES;++i){
                    if(emp[i].exists){
                        printf("%d          ",i);
                        printf("%s          ",emp[i].name);
                        printf("%d          \n",emp[i].age);
                    }
                }
                printf("====================\n");
            break;
            case 5://in case you have done everything or you want to exit you can enter 5 in choice
                printf("Bye\n");
                printf("====================\n");
                return 0;
            break;
        }
    }
}
