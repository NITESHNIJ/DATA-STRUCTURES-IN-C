#include <stdio.h>
#include <stdlib.h>

struct node{
    char name[100];
    int rno;
    struct node* link;
};

void add();
void pop();
void elements();
void display();

struct node* head = NULL;



int main(){
    int n;
    printf("Press:\n");
    printf("1 for push\n");
    printf("2 for pop\n");
    printf("3 for no. of. elements\n");
    printf("4 for display\n");
    printf("5 for stop\n");
    do{
        scanf("%d",&n);
        printf("your choice is: %d\n",n);
        switch(n){
            case 1:
                add();
                break;
            case 2:
                pop();
                break;
            case 3:
                elements();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Bye Bye, nice to serve you");
                break;
        }
    }while(n!=5);
}

void add(){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->link = NULL;
    scanf("%s %d",newnode->name,&newnode->rno);
    if(head == NULL){
        head = newnode;
    }
    else{
        newnode->link = head;
        head = newnode;
    }
    printf("%s with roll-no :%d added succesfully\n",newnode->name,newnode->rno);
    
}
void pop(){
    if(head == NULL){
        printf("Sorry you got nothing to lose\n");
    }
    else{
        printf("%s removed\n",head->name);
        head = head->link;
    }
}

void elements(){
    int count = 0;
    if(head == NULL){
        printf("You got no element in your list\n");
        return;
    }
    else{
    struct node* temp = head;
    while(temp!=NULL){
        temp = temp->link;
        count++;
    }
    printf("The number of elements are:%d\n",count);
    }
}

void display(){
    if(head == NULL){
        printf("Sorry nothing to print\n");
        return;
    }
    else{
        printf("From top(removing end) to bottom:::::\n");
        struct node* temp = head;
        while(temp!=NULL){
            printf("%s with roll-no %d\n",temp->name,temp->rno);
            temp = temp->link;
        }
    }
}