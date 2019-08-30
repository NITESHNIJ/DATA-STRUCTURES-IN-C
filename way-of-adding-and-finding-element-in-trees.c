#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

void add(struct node*, int);
void disp_infix(struct node*);
void find(struct node*, int);


int main(){
    int n,i,val,val2,j;
    printf("Press:");
    printf("1 to add elements\n");
    printf("2 to know if element is present in the list or not\n");
    printf("3 to display in in-order\n");
    printf("4 to exit\n");
    do{
        scanf("%d",&j);
        printf("Your chaoice is %d \n",j);
        switch(j){
            case 1:
                scanf("%d",&n);
                printf("now keep giving %d elements to be added\n",n);
                for(i=0;i<n;i++){
                    scanf("%d",&val);
                    add(root,val);
                }
                break;
            case 2:
                scanf("%d",&val2);
                printf("finding the element %d\n",val);
                find(root,val2);
                break;
            case 3:
                disp_infix(root);
                printf("\n");
                break;
            case 4:
                printf("Bye Bye\n");
        }
    }while(j!=4);
    
    
    
}

void add(struct node* temp, int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    if(root == NULL){
        root = newnode;
        printf("added %d\n",newnode->data);
        return;
    }
    else{
        if(temp->data > val){
            if(temp->left == NULL)
                {temp->left = newnode;
                printf("added element %d\n",newnode->data);}
            else
                add(temp->left, val);
        }
        else{
            if(temp->right == NULL)
                {temp->right = newnode;
                printf("added element %d\n",newnode->data);}
            else
                add(temp->right, val);
        }
    }
}

void disp_infix(struct node* temp){
    if(temp == NULL){
        return;
    }
    disp_infix(temp->left);
    printf("%d  ",temp->data);
    disp_infix(temp->right);
}

void find(struct node* temp,int val){
    if(temp==NULL){
        printf("Element not found\n");
        return;
    }
    if(temp->data == val){
        printf("Element found\n");
        return;
    }
    else{
        if(temp->data > val)
            find(temp->left,val);
        else
            find(temp->right,val);
    }
}