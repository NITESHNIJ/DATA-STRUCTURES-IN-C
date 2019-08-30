#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char arr[100];
int top = -1;
int len;
char exp_arr[100];
int count=99;

int main(){
    int i,ch,j;
    scanf("%s",arr);
    len = strlen(arr);
    for(i=len-1;i>=0;i--){
        arr[i+1] = arr[i];
    }
    char stack[100];
    top = top+1;
    stack[top] = ')';
    arr[0] = '(';
    for(j=len;j>=0;j--){
        ch = arr[j];
        if(ch=='(' || ch==')' || ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%'){
            if(ch == ')'){
                top++;
                stack[top] = ch;
            }
            if(ch == '('){
                while(stack[top]!=')'){
                    exp_arr[count] = stack[top];
                    count--;
                    top--;
                }
                top--;
            }
            if(ch=='*' || ch == '/' || ch == '%'){
                top++;
                stack[top]=ch;
            }
            if(ch=='+' || ch=='-'){
                while(stack[top]!='+' && stack[top]!='-' && stack[top]!=')'){
                    exp_arr[count] = stack[top];
                    top--;
                    count--;
                }
                top++;
                stack[top] = ch;
            }
        }
        else{
            exp_arr[count] = ch;
            count--;
        }
    }
    for(j=count+1;j<100;j++){
        printf("%c ",exp_arr[j]);
    }
}