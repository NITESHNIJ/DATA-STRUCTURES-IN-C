#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *ptr;
int top = -1;

int main(){
    int len,i;
    char ch,bh,flag=0;
    printf("Eneter the stirng here:\n");
    char arr[10000];
    scanf("%[^\n]s",arr);
    printf("The string entered by you is: %s\n",arr);
    len = strlen(arr);
    ptr = (char*)malloc(len*sizeof(char));
    for(i=0;i<len;i++){
        ch = arr[i];
        if(ch=='(' || ch=='{' || ch=='[')
            {   
                top++;
                ptr[top] = ch;
                printf("Found =  %c so now top is %d\n",ch,top);
            }
            
        if(ch==')' || ch=='}' || ch==']')
            {   
                if(top == -1){
                    flag=1;
                    break;
                }
                bh = ptr[top];
                top--;
                if(ch==')' && (bh=='{' || bh=='[')){
                    flag = 1;
                    break;
                }
                if(ch=='}' && (bh=='(' || bh=='[')){
                    flag = 1;
                    break;
                }
                if(ch==']' && (bh=='(' || bh=='{')){
                    flag = 1;
                    break;
                }
              printf("Found =  %c so now top is %d\n",ch,top);   
            }
    }
    if(flag == 1 || top!=-1){
        printf("Invalid");
    }
    else{
        printf("Valid");
    }
}