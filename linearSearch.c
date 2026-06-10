#include<stdio.h>

void searchArray(int arr[],int size,int fValue){

    for(int i=0;i<size;i++){
        if(arr[i]==fValue){
            printf("Index is %d",i);
            return;
        }
    
    }
    printf("Value Not found\n");

}



int main(){

    int size = 5;
    int arr[size];
    int i,fValue;  
    
    printf("Enter 10 Numbers you want to insert\n");

    for(i=0;i<size;i++){
        printf("Enter Number %d:",i);
        scanf("%d",&arr[i]);
    }

    printf("Enter Number you want to find: ");
    scanf("%d",&fValue);

    searchArray(arr,size,fValue);

return 0;

}