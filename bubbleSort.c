#include<stdio.h>

void bubblesort(int arr[], int size){

    int j, i, temp;

    for(i = 0; i < size - 1; i++){

        for(j = 0; j < size - 1 - i; j++){

            if(arr[j] > arr[j + 1]){

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){

    int size = 10;
    int arr[size];
    int i;

    for(i = 0; i < size; i++){
        printf("Enter Number: ");
        scanf("%d", &arr[i]);
    }

    bubblesort(arr, size);

    printf("Bubble sorted numbers: ");

    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
