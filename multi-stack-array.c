#include <stdio.h>
#include <stdlib.h>

void add_a();
void pop_a();
void count_a();
void display_a();
void add_b();
void pop_b();
void count_b();
void display_b();

int n = 5;
int arr[5];
int top_a = -1;
int top_b = 5;

int main(){
    int n;
    printf("Press:\n");
    printf("1 for push in A:\n");
    printf("2 for pop in A:\n");
    printf("3 for no_of_elements in A:\n");
    printf("4 for dispaly in A:\n");
    
    printf("5 for push in B:\n");
    printf("6 for pop in B:\n");
    printf("7 for no of elements in B:\n");
    printf("8 for display in B:\n");
    printf("9 for exit.\n");
    do{
        scanf("%d",&n);
        printf("Your choice is %d\n",n);
        switch(n){
            case 1:
                add_a();
                break;
            case 2:
                pop_a();
                break;
            case 3:
                count_a();
                break;
            case 4:
                display_a();
                break;
            case 5:
                add_b();
                break;
            case 6:
                pop_b();
                break;
            case 7:
                count_b();
                break;
            case 8:
                display_b();
                break;
            case 9:
                printf("Bye Bye nice to seve you!!\n");
                break;
        }
    }while(n!=9);
}

void add_a(){
    int val;
    scanf("%d",&val);
    if(((top_a+1) < top_b) && (top_a < n-1)){
        top_a = top_a + 1;
        arr[top_a] = val;
        printf("Succesfully added %d in array A\n",arr[top_a]);
    }
    else{
        printf("Sorry array A is full\n");
    }
}

void pop_a(){
    if(top_a == -1){
        printf("Stack A is empty\n");
    }
    else{
        printf("%d removed from stack A succesfully\n",arr[top_a]);
        top_a = top_a - 1;
    }
}

void count_a(){
    if(top_a == -1){
        printf("no element in stack A\n");
    }
    else{
        printf("Number of elements in Stack a is %d\n",(top_a+1));
    }
}

void display_a(){
    int i;
    if(top_a == -1){
        printf("No elements in stack a to display");
        return;
    }
    else{
        for(i=0;i<=top_a;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}

void add_b(){
    int val;
    scanf("%d",&val);
    if(((top_b-1)>top_a) && top_b>0){
        top_b--;
        arr[top_b] = val;
        printf("succesfully added %d to stack b\n",arr[top_b]);
    }
    else{
        printf("Sorry but stack B is already full\n");
    }
}


void pop_b(){
    if(top_b == n){
        printf("Sorry but stck B is alredy empty so cannot pop\n");
    }
    else{
        printf("%d succesfully removed from stack B\n",arr[top_b]);
        top_b++;
    }
}

void count_b(){
    if(top_b == n){
        printf("No element in stack B\n");
    }
    else{
    printf("The no of elements in Stack B are:%d\n",(n-top_b));
    }
    
}

void display_b(){
    int i;
    if(top_b == n){
        printf("No elements in Stack B to display\n");
    }
    else{
        for(i=n-1;i>=top_b;i--){
            printf(" -> %d",arr[i]);
        }
        printf("\n");
    }
}