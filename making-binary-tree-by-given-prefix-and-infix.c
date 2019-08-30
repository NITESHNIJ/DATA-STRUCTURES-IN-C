#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node{
    char data;
    struct  node* left;
    struct node* right;
};

void make(struct node*, int, int, int);
void print_infix(struct node*);
void print_prefix(struct node*);
void print_postfix(struct node*);

struct node* root = NULL;
char arr_in[100];
char arr_pre[100];
int ind = 0;

int main(){
    int l;
    printf("Enter the infix:\n");
    scanf("%s",arr_in);
    printf("The enters infix is: %s\n",arr_in);
    printf("Enter the prefix:\n");
    scanf("%s",arr_pre);
    printf("The entered prefix is: %s\n",arr_pre);
    l = strlen(arr_in);
    
    make(root, 0, l, -1);
    
    printf("The infix is: ");
    print_infix(root);
    printf("\n");
    printf("The prefix is: ");
    print_prefix(root);
    printf("\n");
    printf("The postfix is: ");
    print_postfix(root);
    printf("\n");
}

void make(struct node* temp, int l, int h, int flag){
    int i, flag_m=0;
    for(i=l;i<h;i++){
        if(arr_in[i] == arr_pre[ind]){
            flag_m = 1;
            ind++;
            break;
        }
    }
    if(flag_m == 0){
        return;
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = arr_in[i];
    newnode->left = NULL;
    newnode->right = NULL;
    
    if(flag == -1){
        root = newnode;
    }
    else{
        if(flag==0){
            temp->left = newnode;
        }
        else{
            temp->right = newnode;
        }
    }
    
    make(newnode, l, i, 0);
    make(newnode, (i+1), h, 1);
}

void print_infix(struct node* temp){
    if(temp == NULL)
        return;
    print_infix(temp->left);
    printf("%c",temp->data);
    print_infix(temp->right);
}

void print_prefix(struct node* temp){
    if(temp==NULL)
        return;
    printf("%c",temp->data);
    print_prefix(temp->left);
    print_prefix(temp->right);
}

void print_postfix(struct node* temp){
    if(temp==NULL)
        return;
    print_postfix(temp->left);
    print_postfix(temp->right);
    printf("%c",temp->data);
}