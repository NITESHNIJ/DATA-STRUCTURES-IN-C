#include <stdio.h>
#include <stdlib.h>

struct node{
    int front;
    int rear;
    int* ptr;
};

int n,m;
struct node* arr;

void insert();
void delete_i();
void display();

int main(){
    int i,j;
    scanf("%d %d",&n,&m);
    arr = (struct node*)malloc(n*sizeof(struct node));
    for(i=0;i<m;i++){
        arr[i].front = -1;
        arr[i].rear = -1;
        arr[i].ptr = (int*)malloc(m*sizeof(int));
    }
    //geting the elements to be inserted.
    printf("Press 1 for insertion\n");
    printf("Press 2 for deletion\n");
    printf("press 3 to display\n");
    printf("press 4 to exit\n");
    do{
        scanf("%d",&j);
        printf("You pressed %d\n",j);
        switch(j){
            case 1:
                insert();
                break;
            case 2:
                delete_i();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Bye Bye\n");
        }
    }while(j!=4);
}

void insert(){
    int temp_val,temp_prio;
    int temp;
    scanf("%d %d",&temp_val,&temp_prio);
    printf("adding value %d with priority %d\n",temp_val,temp_prio);
    int current_front,current_rear;
    current_front = arr[temp_prio].front;
    current_rear = arr[temp_prio].rear;
    if(current_rear == -1){
        current_front = 0;
        current_rear = 0;
        arr[temp_prio].front = 0;
        arr[temp_prio].rear = 0;
        arr[temp_prio].ptr[current_rear] = temp_val;
        printf("succesfully added %d at priority %d\n",arr[temp_prio].ptr[current_rear],temp_prio);
    }
    else{
        temp = (current_rear+1)%m;
        if(temp == current_front){
            printf("sorry all location for priority: %d are full\n",temp_prio);
        }
        else{
            current_rear = temp;
            arr[temp_prio].rear = temp;
            arr[temp_prio].ptr[current_rear] = temp_val;
            printf("Successfully added %d to the priority %d \n", arr[temp_prio].ptr[current_rear], temp_prio);
        }
    }
}

void delete_i(){
    int i = 0, flag = 0, current_front,current_rear,temp;
    for(i=0;i<n;i++){
        current_front = arr[i].front;
        current_rear = arr[i].rear;
        if(current_front == -1){
            continue;
        }
        else{
            if(current_front==current_rear){
                printf("Popping %d with priority %d\n",arr[i].ptr[arr[i].front],i);
                current_front = -1;
                current_rear = -1;
                arr[i].front = -1;
                arr[i].rear = -1;
                flag = 1;
            }
            else{
                printf("Popping %d with priority %d\n",arr[i].ptr[arr[i].front],i);
                current_front++;
                arr[i].front++;
                flag = 1;
            }
        }
        if(flag == 1){
            break;
        }
    }
    if(flag == 0){
        printf("No element to pop\n");
    }
}

void display(){
    int i, flag=0, current_front, current_rear, j;
    for(i=0;i<n;i++){
        current_front = arr[i].front;
        current_rear = arr[i].rear;
        if(current_front == -1){
            continue;
        }
        else{
            for(j=current_front; j<=current_rear; j++){
                printf("-> %d",arr[i].ptr[j]);
            }
            flag = 1;
        }
    }
    printf("\n");
    if(flag == 0){
        printf("nothing to print in any priority\n");
    }
}