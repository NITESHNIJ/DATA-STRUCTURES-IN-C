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
void disp_prefix(struct node*);
void disp_postfix(struct node*);
void delete_val(struct node*, struct node*, int, int);
int height(struct node*);
void counter(struct node*);
void mirror(struct node*);

int total_nodes = 0,init_nodes = 0,ext_nodes = 0;

int main(){
    int n,i,val,val2,j,del,tree_height;
    printf("Press:");
    printf("1 to add elements\n");
    printf("2 to know if element is present in the list or not\n");
    printf("3 to display in in-order\n");
    printf("4 to display in pre-order\n");
    printf("5 to display in post-order\n");
    printf("6 to exit\n");
    printf("7 for deleting an element\n");
    printf("8 for getting the height of the tree\n");
    printf("9 for getting count of all types of nodes\n");
    printf("10 for mirror-imaging the tree\n");
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
                scanf("%d",&val2);
                printf("finding the element %d\n",val2);
                find(root,val2);
                break;
            case 3:
                printf("the infix is : \n");
                disp_infix(root);
                printf("\n");
                break;
            case 4:
                printf("the prefix is : \n");
                disp_prefix(root);
                printf("\n");
                break;
            case 5:
                printf("the postfix is : \n");
                disp_postfix(root);
                printf("\n");
                break;
            case 6:
                printf("Bye Bye\n");
                break;
            case 7:
                scanf("%d",&del);
                printf("commanded to delete %d\n",del);
                delete_val(root, NULL, del, -1);
                break;
            case 8:
                tree_height = height(root);
                printf("The height of the tree is %d\n",tree_height);
                break;
            case 9:
                counter(root);
                printf("The total number of nodes are : %d\n",total_nodes);
                printf("The internal number of nodes are : %d\n",init_nodes);
                printf("The external number of nodes are : %d\n",ext_nodes);
                break;
            case 10:
                printf("converting the tree to it's mirror image...\n");
                mirror(root);
                break;
        }
    }while(j!=6);
    
    
    
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

void disp_prefix(struct node* temp){
    if(temp == NULL){
        return;
    }
    printf("%d  ",temp->data);
    disp_prefix(temp->left);
    disp_prefix(temp->right);
    
}

void disp_postfix(struct node* temp){
    if(temp == NULL){
        return;
    }
    disp_postfix(temp->left);
    disp_postfix(temp->right);
    printf("%d  ",temp->data);
    
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

void delete_val(struct node* temp, struct node* prev, int val, int flag){
    printf("Currently on node :%d and value to be deleted is: %d\n",temp->data,val);
    if(temp->data == val){
        //printf("I -1.5- ran\n");
    }
    else{
        //printf("I -1- ran\n");
        if(temp->data > val){
            delete_val(temp->left, temp, val, 0);
            return;
        }
        else{
            delete_val(temp->right, temp, val, 1);
            return;
        }
    }
    
    if(temp->left == NULL && temp->right == NULL){
        if(temp == root){
                root = NULL;
        }
        else{
            // printf("even i am reached with a flag value of %d\n",flag);
            //printf("At this moment prev node is %d and previous node's left value is: %d\n",prev->data,prev->left->data);
            if(flag == 0){
                prev->left = NULL;
            }
            else{
                prev->right = NULL;
            }
        }
    }
    
    
    if((temp->left == NULL && temp->right != NULL) || (temp->left != NULL && temp->right == NULL)){
        //printf("I -2- ran\n");
        if(temp->left == NULL){
            //printf("I -3- ran\n");
            if(temp == root){
                root  = temp->right;
            }
            else{
                if(flag == 0){
                    prev->left = temp->right;
                }
                else{
                    prev->right = temp->right;
                }
            }
        }
        else{
            if(temp == root){
                root = temp->left;
            }
            else{
                if(flag == 0){
                    prev->left = temp->left;
                }
                else{
                    prev->right = temp->left;
                }
            }
        }
    }
    
    
    if(temp->left!=NULL && temp->right!=NULL){
        int temp3, temp_flag=0;
        struct node* temp2 = temp->left;
        struct node* temp_prev = temp;
        
        while(temp2->right != NULL){
            temp_prev = temp2;
            temp2 = temp2->right;
            temp_flag = 1;
        }
        temp3 = temp2->data;
        temp2->data = temp->data;
        temp->data = temp3;
        delete_val(temp2, temp_prev, temp2->data, temp_flag);
    }
}


int height(struct node* temp){
    int l_count,r_count,max;
    if(temp == NULL){
        return 0;
    }
    l_count = height(temp->left);
    r_count = height(temp->right);
    if(l_count > r_count){
        max = l_count;
    }
    else{
        max = r_count;
    }
    return max+1;
}

void counter(struct node* temp){
    if(temp == NULL){
        return;
    }
    counter(temp->left);
    total_nodes++;
    if(temp->left==NULL && temp->right == NULL){
        ext_nodes++;
    }
    else{
        init_nodes++;
    }
    counter(temp->right);
}

void mirror(struct node* temp){
    if(temp==NULL){
        return;
    }
    mirror(temp->left);
    mirror(temp->right);
    struct node* hold_temp = temp->left;
    temp->left = temp->right;
    temp->right = hold_temp;
}