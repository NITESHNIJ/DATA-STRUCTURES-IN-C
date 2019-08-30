#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * link;
};

struct node* front = NULL;      //points to the current first node of the list
struct node* rear = NULL;       //points to the current last node of the list

void push();
void pop();
void peek();
void display();

int main(){
    int n;
    printf("Press :\n");
    printf("1 for push\n");
    printf("2 for pop\n");
    printf("3 for peek\n");
    printf("4 for display\n");
    printf("5 for exit\n");
    
    do{
        scanf("%d",&n);
        printf("You entered: %d\n",n);
        switch(n){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("BYe BYe\n");
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
    }while(n!=5);
}

void push(){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->link = NULL;
    scanf("%d",&newnode->data);
    if(rear == NULL){
        rear = newnode;
        front = newnode;
    }
    else{
        rear->link = newnode;
        rear = newnode;
    }
    printf("Pushed %d succcesfully\n",newnode->data);
}

void pop(){
    if(front == NULL){
        printf("nothing in the queue to be popped\n");
        return;
    }
    else{
        if(front == rear){
            printf("Popped:%d\n",front->data);
            front = NULL;
            rear = NULL;
        }
        else{
            printf("Popped:%d\n",front->data);
            front = front->link;
        }
    }
    
}

void peek(){
    int count = 0;
    struct node* temp = front;
    while(temp != NULL){
        count++;
        temp = temp->link;
    }
    printf("Number of elements in the queue are: %d\n",count);
}

void display(){
    if(front == NULL){
        printf("Nothing to display\n");
    }
    else{
        struct node* temp = front;
        while(temp!=NULL){
            printf("-> %d ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}