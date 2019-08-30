#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node* link;
};

struct node* front = NULL;
struct node* rear = NULL;

void insert();

int k;
int n;

int main(){
    int temp_n;
    insert();
    if(front == NULL){
        printf("No player so no game possible\n");
    }
    else{
        scanf("%d",&k);
        printf("every time %d th member will get removed\n",k);
        while(front!=rear){
            int temp_n=k-2;
            struct node* temp = front;
            if(k == 1){
                temp = rear;
            }
            else{
                while(temp_n){
                    temp = temp->link;
                    temp_n--;
                }
            }
            if(front==temp->link){
                front = front->link;
            }
            if(rear==temp->link){
                rear = temp;
            }
            temp->link = temp->link->link;
            rear = temp;
            front = temp->link;
            
        }
    }
    printf("%d is the winner\n",front->num);
}

void insert(){
    int n,i;
    printf("Insertion is inprocess\n");
    scanf("%d",&n);
    printf("making %d players from 1-%d\n",n,n);
    for(i=1;i<=n;i++){
        struct node* newnode;
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->num = i;
        newnode->link = newnode;
        
        if(front==NULL){
            front = newnode;
            rear = newnode;
        }
        else{
            
            newnode->link = front;
            rear->link = newnode;
            rear = newnode;
        }
    }
    //displaying the list
    
    if(front == NULL){
        printf("No elements added\n");
    }
    else{
        struct node* temp = front;
        do{
            printf("-> %d ",temp->num);
            temp = temp->link;
        }while(temp!=front);
        printf("\n");
    }
}