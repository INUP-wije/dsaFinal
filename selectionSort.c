#include<stdio.h>

void selectionSort(int arr[], int size) {
    int smallest;
    int tempVal;
    int j, i;

    for(j = 0; j < size - 1; j++) {
        smallest = j;
        for(i = j + 1; i < size; i++) {

            if(arr[i] < arr[smallest]) {
                smallest = i;
            }
        }
        tempVal = arr[j];
        arr[j] = arr[smallest];
        arr[smallest] = tempVal;
    }
}

int main() {

    int i;
    int size = 10;
    int arr[size];

    for(i = 0; i < size; i++) {
        printf("Enter the Number: ");
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, size);

    printf("Selection sort values: ");

    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}