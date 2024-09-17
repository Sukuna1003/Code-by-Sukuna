#include<stdio.h>
#include<stdlib.h>
#include<string.h>//Including all header files

struct node{//creating linked list using structure
    char data[40];//music initialised as an element
    struct node *next;//pointer pointing to address of next node
    struct node *prev;//pointer pointing to address of previous node
};

char temp[40];//temporary string initialised for copying and other purposes
struct node *head=NULL;//start node initialised as null since no elements present in list
struct node *current_node=NULL;//current node initialised as null for finding specific node

void insert(){//insert function to insert elements in list
    printf("Enter Music Name : ");
    while((getchar())!='\n');
    scanf("%[^\n]%*c",temp);//scanning song input from user
    struct node *new_node=(struct node*)malloc(sizeof(struct node));//new node created and stored
    strcpy(new_node->data,temp);//copying data into the node
    if(head==NULL){//if no element in list use this algorithm
        new_node->next=new_node->prev=new_node;
        head=current_node=new_node;
        return;
    }//else use below algorithm
    struct node *last=head->prev;
    new_node->prev=last;
    last->next=new_node;
    new_node->next=head;
    head->prev=new_node;
}

void Delete_element(){//delete function to delete elements from list
    if(head==NULL){//if no element present print empty list
        printf("No Music is there to delete!\n");
        return;
    }
    printf("Enter Music Name to delete:\n");
    while((getchar())!='\n');//string data scanned from user
    scanf("%[^\n]%*c",temp);
    printf("\n");
    struct node *ptr=head;//else delete element from list using this algorithm
    do{
        if(ptr->next==ptr && strcmp(ptr->data,temp)==0){
            printf("One file deleted! Playlist is Empty Now!\n");
            head=NULL;
            free(ptr);
            return;
        }
        else if(strcmp(ptr->data,temp)==0){
            struct node* prev=ptr->prev;
            struct node* next=ptr->next;
            prev->next=next;
            next->prev=prev;
            head=next;
            free(ptr);
            printf("Music deleted!\n");
            return;
        }
        ptr=ptr->next;
    }while(ptr!=head);
    printf("No Music file is there!\n");
}

void show(){//show function to show elements of list
    if(head==NULL){//if list is empty print empty list
        printf("Playlist is Empty!\n");
        return;}
    struct node* show_ptr=head;
    printf("\n");//else follow this algorithm
    int i=1;
    printf("Displaying Playlist :\n");
    do{
        printf("Song %d : %s\n",i,show_ptr->data);
        i++;
        show_ptr=show_ptr->next;
    }while(show_ptr!=head);
}

void next_node(){//function to goto next node
    if(current_node==NULL){//if empty list print empty list
        printf("No songs in Playlist!\n");
    }
    else{//else follow this algorithm
        current_node=current_node->next;
        printf("Playing Next Song : %s\n",current_node->data);
    }
}

void prev_node(){//function to goto previous node
    if(current_node==NULL){//if empty list print empty list
        printf("No songs in Playlist!\n");
    }
    else{//else follow this algorithm
        current_node=current_node->prev;
        printf("Playing Previous Song : %s\n",current_node->data);
    }
}

void first_node(){//function to go to first node
    if(head==NULL){//if empty list print empty list
        printf("Playlist is Empty!\n");
    }
    else{//else follow this algorithm
        printf("Playing First Music : %s\n",head->data);
    }
}

void last_node(){//function to go to last node
    if(head==NULL){//if empty list print empty list
        printf("Playlist is Empty!\n");
    }
    else{//else follow below algorithm
        printf("Playing Last Music : %s\n",head->prev->data);
    }
}

void specific_data(){//function for specific data
    if(head==NULL){//if empty list print empty list
        printf("No music is there to be searched!\n");
        return;
    }
    printf("Enter Music Name to delete:\n");//else follow below algorithm
    while((getchar())!='\n');
    scanf("%[^\n]%*c",temp);
    printf("\n");
    struct node* ptr=head;
    do{
        if(strcmp(ptr->data,temp)==0){
            printf("Music Found!\n");
            printf("Playing Music : %s\n",ptr->data);
            return;
        }
        ptr=ptr->next;
    }while(ptr!=head);
    printf("There is no Music file with this name!\n");
}

int main(){//main function called
    int choice;//choice variable declared
    menu://printing menu at the top
    printf("-----MUSIC PLAYER APPLICATION-----\n");
    printf("1. Add Music\n");
    printf("2. Remove Music\n");
    printf("3. Show Playlist\n");
    printf("4. Play next file\n");
    printf("5. Play previous file,\n");
    printf("6. Play first file\n");
    printf("7. Play Last file\n");
    printf("8. Play specific file.\n");
    printf("9. Exit\n\n");
    scanf("%d",&choice);
    if (choice == 1)//using algorithms according to different choices
        insert();//insert function used here
    else if (choice == 2)
        Delete_element();//delete function used here
    else if (choice == 3)
        show();//show function used here
    else if (choice == 4)
        next_node();//nextnode function used here
    else if (choice == 5)
        prev_node();//prevnode function used here
    else if (choice == 6)
        first_node();//firstnode function used here
    else if (choice == 7)
        last_node();//lastnode function used here
    else if (choice == 8)
        specific_data();//specificdata function used here
    else
        exit(0);//exit function to exit code
        goto menu;
return 0;
}
