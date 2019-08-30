#include <stdlib.h>
#include <stdio.h>

void push();
void pop();
void peek();
void display();

struct node{
    int data;
    struct node* link;
};

struct node* front = NULL;
struct node* rear = NULL;

int main(){
    int n;
    printf("Press:");
    printf("1 for push\n");
    printf("2 for pop\n");
    printf("3 for number of elements\n");
    printf("4 for display\n");
    printf("5 for exit\n");
    do{
        scanf("%d",&n);
        printf("You entered :%d\n",n);
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
                printf("Nice to serve you!! Bye Bye");
                break;
        }
    }while(n!=5);
}

void push(){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->link = newnode;
    
    if(rear == NULL){
        front = newnode;
        rear = newnode;
        printf("pushed: %d\n",rear->data);
    }
    else{
        newnode->link = front;
        rear->link = newnode;
        rear = newnode;
        printf("Pushed : %d\n",rear->data);
    }
}

void pop(){
    if(front==NULL){
        printf("nothing to pop\n");
    }
    else{
        if(front == rear){
            printf("Popped: %d\n",front->data);
            front = NULL;
            rear = NULL;
        }
        else{
            printf("Popped : %d\n",front->data);
            rear->link = front->link;
            front = front->link;
        }
    }
}

void peek(){
    int count;
    if(front==NULL){
        printf("no element in the list\n");
    }
    else{
        struct node* temp = front;
        do{
            count++;
            temp = temp->link;
        }while(temp!=front);
        printf("the number of elements are : %d\n",count);
    }
        
}

void display(){
    int count = 0;
    if(front==NULL){
        printf("no element in the list to dispaly\n");
    }
    else{
        struct node* temp = front;
        do{
            printf("-> %d",temp->data);
            temp = temp->link;
        }while(temp!=front);
        printf("\n");
    }
}