#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    int prio;
    struct node* link;
};

struct node* front = NULL;
struct node* rear = NULL;

void insert();
void delete_i();
void display();

int main(){
    int j;
    printf("Press 1 for insertion\n");
    printf("Press 2 for deletion\n");
    printf("press 3 to display\n");
    printf("press 4 to exit\n");
    do{
        scanf("%d",&j);
        printf("You pressed %d\n",j);
        switch(j){
            case 1:
                insert();
                break;
            case 2:
                delete_i();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Bye Bye\n");
        }
    }while(j!=4);
}

void insert(){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->link = NULL;
    scanf("%d %d",&newnode->data,&newnode->prio);
    if(front == NULL){
        front = newnode;
        rear = newnode;
        printf("Pushed %d with priority %d \n",front->data,front->prio);
    }
    else{
        if(front->prio > newnode->prio){
            newnode->link = front;
            front = newnode;
            printf("Pushed %d with priority %d \n",front->data,front->prio);
            
        }
        else{
            if(rear->prio <= newnode->prio){
                rear->link = newnode;
                rear = newnode;
                printf("Pushed %d with priority %d \n",rear->data,rear->prio);
            }
            else{
                struct node* temp = front;
                while(!((temp->prio <= newnode->prio) && (temp->link->prio > newnode->prio))){
                    temp = temp->link;
                }
                newnode->link = temp->link;
                temp->link = newnode;
                printf("Pushed %d with priority %d \n",temp->link->data,temp->link->prio);
            }
        }
    }
}

void delete_i(){
    if(front == NULL){
        printf("Nothing to pop\n");
    }
    else{
        if(front == rear){
            printf("popped %d with priority %d\n",front->data,front->prio);
            front = NULL;
            rear = NULL;
        }
        else{
            printf("popping %d with priority %d \n",front->data,front->prio);
            front = front->link;
        }
    }
}

void display(){
    if(front == NULL){
        printf("Nothing to display\n");
    }
    else{
        struct node* temp = front;
        while(temp != NULL){
            printf("-> %d(%d) ",temp->data,temp->prio);
            temp = temp->link;
        }
        printf("\n");
    }
}