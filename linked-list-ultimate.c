#include<stdio.h>
#include<stdlib.h>

//LINKED LIST
struct node{
    int data;
    struct node* link;
};


void display();
void add_beginning();
void add_at_n();
void add_at_end();
void del_beg();
void del_at_n();
void del_at_end();
void reverse(struct node*, struct node*);
void no_of_ele_print();
void swap();

int no_of_ele = 0;
struct node* head = NULL;

int main(){
    int a;
    printf("press:\n");
    printf("1 for displaying the list\n");
    printf("2 for add element to list at beggining\n");
    printf("3 for adding element at nth place of the list\n");
    printf("4 for adding element at the last of the list\n");
    printf("5 for deleting element at beggining of the list\n");
    printf("6 for deleting element at the nth place of the list\n");
    printf("7 for deleting element from end\n");
    printf("8 for reversing the list\n");
    printf("9 for finding the no of elements in the list\n");
    printf("10 for stopping\n");
    printf("11 for reversing any two consecutive elements");
    
    do{
        
        scanf("%d",&a);
        printf("Your choice is: %d\n",a);
        switch(a){
            case 1:
                display();
                break;
            case 2:
                add_beginning();
                break;
            case 3:
                add_at_n();
                break;
            case 4:
                add_at_end();
                break;
            case 5:
                del_beg();
                break;
            case 6:
                del_at_n();
                break;
            case 7:
                del_at_end();
                break;
            case 8:
                //struct node* prev = NULL;
                //struct node* current = head;
                reverse(NULL, head);
                break;
            case 9:
                no_of_ele_print();
                break;
            case 11:
                swap();
                break;
            default:
                printf("Bye, nice to serve you\n");
                break;
        }
    }while(a!=10);
    return 0;
}

void display(){
    if(head==NULL){
        printf("The list is empty\n");
    }
    else{
        struct node* temp = head;
        while(temp!=NULL){
            printf(" -> %d",temp->data);
            temp = temp->link;
        }
    }
    printf("\n");
}

void add_beginning(){
    no_of_ele++;
    int ele;
    scanf("%d",&ele);
    printf("The element to be added to the beginning is: %d\n",ele);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->link = head;
    head = newnode;
}

void add_at_n(){
    int n, ele,count=0;
    scanf("%d",&n);
    scanf("%d",&ele);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->link = NULL;
    printf("The element are to be added at index %d , value is %d\n",n,ele);
    if(no_of_ele<n){
        printf("appending at the end as no of elements less than the position demanded\n");
        struct node* temp = head;
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = newnode;
    }
        else{
        struct node* temp = head;
        while(count<n-1){
            temp = temp->link;
            count++;
        }
        newnode->link = temp->link;
        temp->link = newnode;
    }
    no_of_ele++;
}

void add_at_end(){
    int ele;
    scanf("%d",&ele);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->link = NULL;
    printf("%d getting appended to the end\n",ele);
    struct node* temp = head;
    while(temp->link != NULL){
        temp = temp->link;
    }
    temp->link = newnode;
    no_of_ele++;
}

void del_beg(){
        struct node* temp = head;
        head = head->link;
        no_of_ele--;
        free(temp);
}

void del_at_n(){
    int count=0,n;
    scanf("%d",&n);
    struct node* temp = head;
    if(no_of_ele<n){
        printf("As no of elements are less than given index so deleting the last\n");
        while(temp->link->link!= NULL){
            temp = temp->link;
        }
        temp->link = NULL;
    }
    else{
        while(count<n-1){
            temp = temp->link;
            count++;
        }
        temp->link = temp->link->link;
    }
    no_of_ele--;
}

void del_at_end(){
    if(head == NULL){
        printf("list empty");
    }
    else{
        if(no_of_ele==1){
            head = NULL;
        }
        else{
            struct node* temp = head;
            while(temp->link->link!= NULL){
                temp = temp->link;
        }
        temp->link = NULL;
    
        no_of_ele--;
        }
    }
}

void reverse(struct node* prev, struct node* current){
    if(current == NULL){
        head = prev;
        return;
    }
    reverse(current, current->link);
    current->link = prev;
}

void no_of_ele_print(){
    printf("no of elements currently in the list are:%d\n",no_of_ele);
}

void swap(){
    int n,count;
    scanf("%d",&n);
    n = n-1;
    printf("swapping the element at index(beggining from 1, cannot swap the 0 index element) number %d and %d....\n",n,(n+1));
    count = 0;
    struct node* ptr1 = head;
    while(count<n){
        ptr1 = ptr1->link;
        count++;
    }
    struct node* ptr2 = ptr1->link;
    struct node* temp = ptr2->link;
    ptr1->link = ptr2->link;
    ptr2->link = ptr2->link->link;
    temp->link = ptr2;
    
}