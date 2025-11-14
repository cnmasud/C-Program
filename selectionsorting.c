#include<stdio.h>
int main(){
    int arr[]={32,44,76,23,87,12,98};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int i,j,min;
    for(i=0; i<size; i++){
        min = i;
        for(j=i+1; j<size;j++){
            if(arr[min]< arr[j]){
                min = j;
            }
        }
        if(min != i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    for(i=0;i<size;i++){
        printf("%d ", arr[i]);
        
    }
    
    
    
    return 0; 
}

