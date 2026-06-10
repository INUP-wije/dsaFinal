#include<stdio.h>

void merge(int arr[], int start, int middle, int end) {

    int n1 = middle - start + 1;
    int n2 = end - middle;

    int Left[n1], Right[n2];

    for(int i = 0; i < n1; i++)
        Left[i] = arr[start + i];

    for(int j = 0; j < n2; j++)
        Right[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        } else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int start, int end) {

    if (start < end) {

        int middle = (start + end) / 2;

        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);   

        merge(arr, start, middle, end);
    }
}

int main() {

    int size = 10;
    int arr[size];

    for(int i = 0; i < size; i++) {
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, size - 1);


    printf("Sorted array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}