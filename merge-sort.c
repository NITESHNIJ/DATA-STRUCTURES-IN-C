#include<stdio.h>
#include<stdlib.h>
void rec(int,int);
int* ptr;
void merge(int,int,int);

int main() {
    int low=0,n,upper,i,f;
    scanf("%d",&n);
    ptr = (int*)malloc(n*sizeof(int));
    upper = n-1;
    for(i=0;i<n;i++){
        scanf("%d",&ptr[i]);
    }
    rec(low,upper);
    for(f=low;f<=upper;f++){
        printf("%d ",ptr[f]);
    }
}

void rec(int low,int high){
    int mid;
    if(low>=high)
        return;
    mid = (int)((low+high)/2);
    rec(low,mid);
    rec(mid+1,high);
    merge(low,mid,high);
}

void merge(int low,int mid,int high){
    int temp[high];
    int i=low,j=mid+1,count=0,f,g,k;
    while(i<=mid && j<=high){
        if(ptr[i]<ptr[j]){
            temp[count] = ptr[i];
            count++;
            i++;
        }
        else{
            temp[count] = ptr[j];
            count++;
            j++;
        }
    }
    for(f=i;f<=mid;f++){
        temp[count] = ptr[f];
        count++;
    }
    for(g=j;g<=high;g++){
        temp[count] = ptr[g];
        count++;
    }
    int begin=0;
    for(k=low;k<=high;k++){
        ptr[k] = temp[begin];
        begin++;
    }
}