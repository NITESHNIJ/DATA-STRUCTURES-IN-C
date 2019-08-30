// interpolation search is a serching algorithm , improvement of binary search, it takes time as log(log(n)) in it's best case and O(n) in worst case
// it expects input array in sorted order.
#include <stdio.h>

int main(){
    int n,i,e,start,end,flag,pos;
    //double start,end;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&e);
    
    start = 0.0;
    end = n-1;
    flag = 0;
    while(start<=end){
        pos = start + ((double)((end-start)*(1.0)/(arr[end]-arr[start]))*(e-arr[start]));
        if(arr[pos] == e){
            flag = 1;
            break;
        }
        else{
            if(arr[pos]<e){
                start = pos+1;
            }
            else{
                end = pos-1;
            }
        }
    }
    if(flag==0){
        printf("Element not found so better give the correct input");
    }
    else{
        printf("the element is found at %d",(pos+1));
    }
    
}