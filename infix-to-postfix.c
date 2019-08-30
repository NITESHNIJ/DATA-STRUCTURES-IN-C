#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr[100];
int top = -1;
int len;
void prefix_to_postfix();

int main(){

    scanf("%s",arr);
    len = strlen(arr);
    printf("The entered srting is : %s and length is :%d \n",arr,len);
    arr[len] = ')';
    len = strlen(arr);
    
    prefix_to_postfix();
}

void prefix_to_postfix(){
    int exp_current = 0;
    char ch;
    int i;
    char stack[len];
    char exp[len];
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
                    exp[exp_current] = stack[top];
                    exp_current++;
                    top--;
                }
                top--;
            }
            if(ch=='+' || ch=='-'){
                while(stack[top]!='('){
                    exp[exp_current] = stack[top];
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
                        exp[exp_current] = stack[top];
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
            exp[exp_current] = ch;
            exp_current++;
        }
    }
    printf("\nThe final expression is :");
    for(i=0;i<exp_current;i++)
        printf("%c",exp[i]);
}