#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node* link;
};

void add_ele();
void display();
void reverse(struct node*);

int n;
int top = -1;
struct node* head = NULL;
struct node** arr;

int main(){
    int i;
    printf("Enter the number of elements in your list:\n");
    scanf("%d",&n);
    arr = (struct node**)malloc(n*sizeof(struct node*));
    printf("You need to give %d no of elements\n",n);
    for(i=0;i<n;i++){
        add_ele();
    }
    display();
    struct node* temp = head;
    reverse(temp);
    display();
}

void add_ele(){
    int val;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->link = NULL;
    scanf("%d",&newnode->data);
    if(head == NULL){
        head = newnode;
    }
    else{
        struct node* temp = head;
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = newnode;
    }
}

void display(){
    if(head == NULL){
        printf("list is empty\n");
    }
    else{
        struct node* temp = head;
        while(temp!=NULL){
            printf(" -> %d",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void reverse(struct node* temp){
    if(temp == NULL){
        head = arr[top];
        top--;
        return;
    }
    top++;
    arr[top] = temp;
    reverse(temp->link);
    if(top != -1){
        temp->link = arr[top];
        top--;
    }
    else{
        temp->link = NULL;
    }
}