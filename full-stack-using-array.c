#include <stdio.h>
#include <stdlib.h>

struct node{
    char name[100];
    int rno;
};

void add();
void pop();
void elements();
void display();

int max = 3;
struct node* arr[3];
int top = -1;



int main(){
    int i,n;
    for(i=0;i<max;i++){
        arr[i] = (struct node*)malloc(sizeof(struct node));
    }
    
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
    char temp_name[100];
    int temp_rno;
    if(top==(max-1)){
        scanf("%s %d",temp_name,&temp_rno);
        printf("Sorry but the stack is full\n");
        return;
    }
    else{
        top = top + 1;
        scanf("%s %d",arr[top]->name,&arr[top]->rno);
        printf("Added the name %s and roll no %d succesfully\n",arr[top]->name,arr[top]->rno);
    }
}

void pop(){
    if(top == -1){
        printf("Sorry the stack is empty\n");
        return;
    }
    else{
        char *temp;
        temp = arr[top]->name;
        top = top - 1;
        printf("Popped %s sucessfully\n",temp);
        if(top==-1){
            printf("With this the stack is now empty\n");
        }
    }
}

void elements(){
    if(top == -1){
        printf("The array is empty");
    }
    else{
        printf("Total no of users in stack are: %d\n",(top +1));
    }
}

void display(){
    int i;
    if(top == -1){
        printf("Stack empty");
    }
    for(i=0;i<=top;i++){
        printf("name:%s  roll-no:%d\n",arr[i]->name,arr[i]->rno);
    }
}