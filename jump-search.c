// jump search
#include <stdio.h>
int main(){
    int n,i,e,step = 3,start,flag,end,j,k;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&e);
    start=0;
    flag = 0;
    end = n-1;
    i=0;
    j = i+step-1;
    while(!(arr[i]<=e && arr[j]>=e) && !(j==end)){
        i = j+1;
        j = j+step;
        if(i>end)
            i = end;
        if(j>end)
            j = end;
    }
    for(k=i;k<=j;k++){
        if(arr[k] == e){
            printf("element found at %d\n",(k+1));
            flag = 1;
        }
    }
    if(flag == 0){
        printf("Element found illaeye");
    }
}
