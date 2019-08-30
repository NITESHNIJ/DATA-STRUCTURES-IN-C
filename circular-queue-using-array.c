#include <stdlib.h>
#include <stdio.h>

void push();
void pop();
void peek();
void display();

int arr[5];
int n = 5;
int front = -1;
int rear = -1;

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
            default:
                printf("wrong choice");
        }
    }while(n!=5);
}

void push(){
    int val,temp;
    scanf("%d",&val);
    if(rear==-1){
        front = 0;
        rear = 0;
        arr[rear] = val;
        printf("Pushed : %d\n",arr[rear]);
    }
    else{
        temp = (rear+1)%n;
        if(temp == front){
            printf("Overflow\n");
        }
        else{
            rear = temp;
            arr[rear] = val;
            printf("Pushed : %d\n",arr[rear]);
        }
    }
}

void pop(){
    int temp;
    if(front==-1){
        printf("Underflow\n");
    }
    else{
        temp = (front+1)%n;
        if(front == rear){
            printf("Popped : %d\n",arr[front]);
            front = -1;
            rear = -1;
        }
        else{
            printf("Popped: %d\n",arr[front]);
            front = temp;;
        }
    }
}

void peek(){
    int temp;
    if(front == -1){
        printf("no elements to display\n");}
    else{
        temp = (rear-front+n+1)%n;
        if(temp == 0)
            printf("Total number of elements are: 5\n");
        else
            printf("Number of elements are %d:\n",temp);
    }
        
}

void display(){
    int i;
    if(front==-1){
        printf("Nothing to display\n");
    }
    else{
        do{
            i = (i+1)%n;
            printf("-> %d",arr[i]);
        }while(i!=rear);
        printf("\n");
    }
    
}