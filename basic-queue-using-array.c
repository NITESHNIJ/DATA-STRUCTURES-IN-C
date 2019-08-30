#include <stdio.h>
#include <stdlib.h>


void push();
void pop();
void peek();
void display();

int arr[100];
int front = -1;
int rear = -1;

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
    int temp;
    scanf("%d",&temp);
    if(front == -1 & rear == -1){
        front++;
        rear++;
        arr[front] = temp;
    }
    else{
        rear++;
        arr[rear] = temp;
    }
}

void pop(){
    if(front==rear){
        printf("Sucessfully removed: %d\n",arr[front]);
        front = -1;
        rear = -1;
    }
    else{
        front++;
    }
}

void peek(){
    if(front==-1){
        printf("No elements to dispaly\n");
    }
    else{
        printf("Number of elements are %d\n",(rear-front+1));
    }
}

void display(){
    int i;
    if(front==-1){
        printf("Have nothing to diplay\n");
    }
    else{
        for(i=front;i<=rear;i++){
            printf("-> %d ",arr[i]);
        }
        printf("\n");
    }
}