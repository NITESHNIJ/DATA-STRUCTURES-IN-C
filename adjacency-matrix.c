#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
    int flag_l;
    int flag_r;
};



struct node* root = NULL;

void add(struct node*, int);
void disp_infix(struct node*);
void threading(struct node*);
void threaded_disp_infix(struct node*);

int top = -1;
struct node* stack[100];

struct node* shitty;

int main(){
    int n,i,val,j;
    printf("Press:");
    printf("1 to add elements\n");
    printf("2 to traverse before threading\n");
    printf("3 do threading\n");
    printf("4 to display in in-order after threading\n");
    printf("5 to exit\n");
    do{
        scanf("%d",&j);
        printf("Your choice is %d \n",j);
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
                printf("The infix is:");
                printf("\n");
                disp_infix(root);
                printf("\n");
                break;
            case 3:
                
                shitty = (struct node*)malloc(sizeof(struct node));
                shitty->flag_l=1;
                shitty->flag_r=1;
                shitty->left = root;
                shitty->right = shitty;
                shitty->data = 0;
                
                top++;
                stack[top] = shitty;
                
                threading(root);
                
                struct node* popper = stack[top];
                popper->right = shitty;
                popper->flag_r = 1;
                
                break;
            case 4:
                threaded_disp_infix(root);
                break;
            case 5:
                printf("Bye Bye\n");
                break;
        }
    }while(j!=5);
    
    
    
}

void add(struct node* temp, int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->flag_l = 0;
    newnode->flag_r = 0;
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


void threading(struct node* temp){
    if(temp==NULL)
        return;
    
    threading(temp->left);
    
    if(temp->left == NULL){
        temp->left = stack[top];
        temp->flag_l = 1;
    }
    
    struct node* popper = stack[top];
    if(popper->right == NULL){
        popper->right = temp;
        popper->flag_r = 1;
    }
    top++;
    stack[top] = temp;
    
    threading(temp->right);
    
}

void threaded_disp_infix(struct node* temp){
    if(temp->data == 0){
        printf("\nshitty reached\n");
        return;
    }
    printf("%d -> ",temp->data);
    threaded_disp_infix(temp->right);
}