#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[7]={100, 80, 60, 70, 60, 75, 85};
    int span_stock[7];
    span_stock[0]=arr[0];
    for(int i=1;i<7;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[i]<arr[j]){
                span_stock[i]=arr[j];
                break;
            }
        }
    }
    for(int i=0;i<7;i++){
        printf("%d ",span_stock[i]);
    }
    return 0;
}