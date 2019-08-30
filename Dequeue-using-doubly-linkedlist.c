#include <stdlib.h>
#include <stdio.h>

void push_front();
void pop_front();
void push_rear();
void pop_rear();
void peek();
void display();

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* front = NULL;
struct node* rear = NULL;

int main(){
    int n;
    printf("Press:");
    printf("1 for push_front\n");
    printf("2 for pop_front\n");
    printf("3 for push_rear\n");
    printf("4 for pop_rear\n");
    printf("5 for number of elements\n");
    printf("6 for display\n");
    printf("8 for exit\n");
    do{
        scanf("%d",&n);
        printf("You entered :%d\n",n);
        switch(n){
            case 1:
                push_front();
                break;
            case 2:
                pop_front();
                break;
            case 3:
                push_rear();
                break;
            case 4:
                pop_rear();
                break;
            case 5:
                peek();
                break;
            case 6:
                display();
                break;
            case 8:
                printf("Bye Bye");
                break;
        }
    }while(n!=8);
}

void push_front(){
    struct node* newnode;
    scanf("%d",&newnode->data);
    newnode->left = NULL;
    newnode->right = NULL;
    
    if(front == NULL){
        front = newnode;
        rear = newnode;
        printf("pushed to front : %d\n",front->data);
    }
    else{
        newnode->right = front;
        front->left = newnode;
        front = newnode;
        printf("Pushed tofront : %d\n",front->data);
    }
}

void pop_front(){
    if(front==NULL){
        printf("Empty\n");
    }
    else{
        if(front == rear){
            printf("popping from front : %d\n",front->data);
            front = NULL;
            rear = NULL;
        }
        else{
            printf("Popping from front : %d\n",front->data);
            front = front->right;
            front->left = NULL;
        }
    }
}

void peek(){
    int count = 0;
    if(front == NULL){
        printf("0 elements present\n");
    }
    else{
        struct node* temp = front;
        while(temp!=NULL){
            count++;
            temp = temp->right;
        }
        printf("number of elements present are: %d\n",count);
        
    }
}

void display(){
    if(front == NULL){
        printf("Nothing to display\n");
    }
    else{
        struct node* temp = front;
        while(temp!=NULL){
            printf("-> %d",temp->data);
            temp = temp->right;
        }
        printf("\n");
        
    }
}

void push_rear(){
    struct node* newnode;
    scanf("%d",&newnode->data);
    newnode->left = NULL;
    newnode->right = NULL;
    
    if(rear == NULL){
        front = newnode;
        rear = newnode;
        printf("Pushed to rear: %d\n",rear->data);
    }
    else{
        newnode->left = rear;
        rear->right = newnode;
        rear = newnode;
        printf("Pushing to rear: %d\n",rear->data);
    }
}

void pop_rear(){
    if(rear == NULL){
        printf("empty\n");
    }
    else{
        if(rear == front){
            printf("Popping from rear:%d\n",rear->data);
            front = NULL;
            rear = NULL;
        }
        else{
            printf("popping from rear:%d\n",rear->data);
            rear = rear->left;
            rear->right = NULL;
        }
    }
}