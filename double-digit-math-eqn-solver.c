#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr[100];
int top = -1;
int len;
void prefix_to_postfix();
void evaluate_post_fix();

int main(){

    scanf("%s",arr);
    len = strlen(arr);
    printf("The entered srting is : %s and length is :%d \n",arr,len);
    arr[len] = ')';
    len = strlen(arr);
    
    prefix_to_postfix();
    evaluate_post_fix();
}
char exp_arr[100];
int exp_current = 0;

void prefix_to_postfix(){
    char ch;
    int i,flag=0;
    char stack[len];
    top=top+1;
    stack[top] = '(';
    for(i=0;i<len;i++){
        ch = arr[i];
        if(ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%' || ch == '(' || ch== ')'){
            if(flag==1){
                exp_arr[exp_current] = ' ';
                exp_current++;
                flag=0;
            }
            if(ch == '('){
                top++;
                stack[top] = ch;
            }
            if(ch==')'){
                while(stack[top]!='('){
                    exp_arr[exp_current] = stack[top];
                    exp_current++;
                    exp_arr[exp_current] = ' ';
                    exp_current++;
                    top--;
                }
                top--;
            }
            if(ch=='+' || ch=='-'){
                while(stack[top]!='('){
                    exp_arr[exp_current] = stack[top];
                    exp_current++;
                    exp_arr[exp_current] = ' ';
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
                        exp_arr[exp_current] = stack[top];
                        exp_current++;
                        exp_arr[exp_current] = ' ';
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
            exp_arr[exp_current] = ch;
            exp_current++;
            flag=1;
        }
    }
    printf("\nThe final expression is :");
    for(i=0;i<exp_current;i++)
        printf("%c",exp_arr[i]);
}

void evaluate_post_fix(){
    exp_current--;                  //to avoid the last space
    int i,flag=0,val=0,val1,val2;
    float val3;
    char ch;
    float new_stack[100];
    int new_top=-1;
    for(i=0;i<exp_current;i++){
        ch = exp_arr[i];
            switch(ch){
                case ' ':
                    if(flag==1){
                        new_top++;
                        new_stack[new_top] = val;
                        val=0;}
                    break;
                case '0':
                    flag=1;
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    val = val*10 +(((int)ch) - 48);
                    flag=1;
                    break;
                default:
                    val2 = new_stack[new_top];
                    new_top--;
                    val1 = new_stack[new_top];
                    new_top--;
                    switch(ch){
                        case '+':
                            val3 = val1 + val2;
                            break;
                        case '-':
                            val3 = val1 - val2;
                            break;
                        case '*':
                            val3 = val1 * val2;
                            break;
                        case '/':
                            val3 = val1 / val2;
                            break;
                        case '%':
                            val3 = val1 % val2;
                            break;
                    }
                    new_top++;
                    new_stack[new_top] = val3;
                    flag=0;
                    break;
            }
    }
    printf("\n%f",new_stack[new_top]);
}