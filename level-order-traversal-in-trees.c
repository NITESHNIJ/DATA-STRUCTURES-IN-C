//BINARY TREE
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

struct node* ptr[100];

void add();
void pre_tra(struct node*);
void in_tra(struct node*);
void post_tra(struct node*);
void level_tra(struct node*);

int main(){
    int a;
    printf("Press:\n");
    printf("1 to add an element\n");
    printf("2 for pre-order traversal\n");
    printf("3 for in order traversal\n");
    printf("4 for post-order traversal\n");
    printf("5 for level-order traversal\n");
    do{
        scanf("%d",&a);
        switch(a){
            case 1:
                printf("you presses 1\n");
                add();
                break;
            case 2:
                printf("you presses 2\n");
                if(root == NULL){
                    printf("no element in the tree\n");
                }
                else{
                    printf("pre-order:\n");
                    pre_tra(root);
                }
                break;
            case 3:
                printf("you presses 3\n");
                if(root == NULL){
                    printf("no element in the tree\n");
                }
                else{
                    printf("in-order:\n");
                    in_tra(root);
                }
                break;
            case 4:
                printf("you presses 4\n");
                if(root == NULL){
                    printf("no element in the tree\n");
                }
                else{
                    printf("post-order:\n");
                    post_tra(root);
                }
                break;
            case 5:
                printf("you pressed 5\n");
                printf("level-order:\n");
                level_tra(root);
                break;
            case 10:
                printf("\nBye");
                break;
            default:
                printf("Invalid Input");
                break;
        }
        
    }while(a!=10);
}

void add(){
    int n,pos;
    struct node* prev;
    struct node* temp = root;
    
    scanf("%d",&n);
    printf("the no %d is added\n",n);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->left = NULL;
    newnode->right = NULL;
    
    if(root == NULL){
        root = newnode;
    }
    else{
        while(temp!=NULL){
            if(n > temp->data){
                prev = temp;
                temp = temp->right;
                pos = 1;
            }
            else{
                prev = temp;
                temp = temp->left;
                pos = 0;
            }
        }
        if(pos == 1){
            prev->right = newnode;
        }
        else{
            prev->left = newnode;
        }
    }
}

void pre_tra(struct node* head){
    if(head==NULL)
        return;
    
    printf("-> %d ",head->data);
    pre_tra(head->left);
    pre_tra(head->right);
    
}

void in_tra(struct node* head){
    if(head==NULL)
        return;
    
    in_tra(head->left);
    printf("-> %d ",head->data);
    in_tra(head->right);
}

void post_tra(struct node* head){
    if(head==NULL)
        return;
    
    post_tra(head->left);
    post_tra(head->right);
    printf("-> %d ",head->data);
}

void level_tra(struct node* temp){
    struct node* head;
    int count = 1,pos=0;
    ptr[0] = temp;
    do{
        head = ptr[pos];
        printf("-> %d ",head->data);
        
        if(head->left != NULL){
            ptr[count] = head->left;
            count++;
        }
        if(head->right != NULL){
            ptr[count] = head->right;
            count++;
        }
        pos++;
    }while(pos<count);
    
    
}