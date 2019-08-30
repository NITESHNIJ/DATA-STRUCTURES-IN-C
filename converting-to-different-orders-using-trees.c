#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr[100];
int top = -1;
int len;
char exp_i[100];
int exp_current = 0;

void prefix_to_postfix();
void make_binary();
void print_prefix();
void print_postfix();
void print_inorder();

struct node{
    char ch;
    struct node* left;
    struct node* right;
};

struct node* root;                      //this will contsin the binary tree made by the post order
struct node *stack_conv[100];

int main(){

    scanf("%s",arr);
    len = strlen(arr);
    printf("The entered srting is : %s and length is :%d \n",arr,len);
    arr[len] = ')';
    len = strlen(arr);
    
    prefix_to_postfix();    //now exp_i holds the postfix expression with exp_current holding it's length ie l,ie last index is l-1;
    
    make_binary();
    printf("\n the prefix expression is:  ");
    
    print_prefix(root);
    
    printf("\n the inorder expression is:  ");
    print_inorder(root);
   
    printf("\n the post order expression is:  ");
    print_postfix(root);
    
}

void prefix_to_postfix(){
    char ch;
    int i;
    char stack[len];
    top=top+1;
    stack[top] = '(';
    for(i=0;i<len;i++){
        ch = arr[i];
        if(ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%' || ch == '(' || ch== ')'){
            if(ch == '('){
                top++;
                stack[top] = ch;
            }
            if(ch==')'){
                while(stack[top]!='('){
                    exp_i[exp_current] = stack[top];
                    exp_current++;
                    top--;
                }
                top--;
            }
            if(ch=='+' || ch=='-'){
                while(stack[top]!='('){
                    exp_i[exp_current] = stack[top];
                    exp_current++;
                    top--;
                }
                top++;
                stack[top] = ch;
            }
            if(ch=='%' || ch=='/' || ch=='*'){
                if(stack[top] == '+' ||stack[top]=='-' || stack[top]=='('){
                    top = top+1;
                    stack[top] = ch;
                }
                else{if(stack[top]=='*'||stack[top]=='/'||stack[top]=='%'){
                    while(stack[top]!='+' && stack[top]!='-' && stack[top]!='('){
                        exp_i[exp_current] = stack[top];
                        exp_current++;
                        top--;
                    }
                    top = top+1;
                    stack[top] = ch;
                }
              }
            }
        }
        else{
            exp_i[exp_current] = ch;
            exp_current++;
        }
    }
    printf("\nThe final expression is :");
    for(i=0;i<exp_current;i++)
        printf("%c",exp_i[i]);
}


void make_binary(){
    int i,ch,stack_top = -1;
    
    printf("\nConverting %s to binary tree form\n",exp_i);
    for(i=0;i<exp_current;i++){
        ch = exp_i[i];
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%'){
            struct node* ptr;
            struct node* prev1;
            struct node* prev2;
            ptr = (struct node*)malloc(sizeof(struct node));
            ptr->left = NULL;
            ptr->right = NULL;
            ptr->ch = ch;
            prev1 = stack_conv[stack_top];
            stack_top--;
            prev2 = stack_conv[stack_top];
            stack_top--;
            ptr->left = prev2;
            ptr->right = prev1;
            stack_top++;
            stack_conv[stack_top] = ptr;
        }
        else{
            struct node* ptr;
            ptr = (struct node*)malloc(sizeof(struct node));
            ptr->ch = ch;
            ptr->left = NULL;
            ptr->right = NULL;
            stack_top++;
            stack_conv[stack_top] = ptr;
        }
    }
    root = stack_conv[stack_top];
    printf("root->ch: %c\n",root->ch);
    printf("root->left->ch: %c\n",root->left->ch);
    printf("root->right->ch: %c\n",root->right->ch);
    printf("root->right->left->ch: %c\n",root->right->left->ch);
    printf("root->right->right->ch: %c\n",root->right->right->ch);
}


void print_prefix(struct node*temp){
    if(temp == NULL)
        return;
    printf("%c",temp->ch);
    print_prefix(temp->left);
    print_prefix(temp->right);
}

void print_inorder(struct node* temp){
    if(temp == NULL)
        return;
    
    printf("( ");
    print_inorder(temp->left);
    printf("%c",temp->ch);
    print_inorder(temp->right);
    printf(" )");
}

void print_postfix(struct node* temp){
    if(temp == NULL)
        return;
    print_postfix(temp->left);
    print_postfix(temp->right);
    printf("%c",temp->ch);
}