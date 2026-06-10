#include<stdio.h>
#include<string.h>

#define size 5

struct node{
    char name[50];
    int contactNumber;
};

void sortarray(struct node directroy[]){
    int i,j;
    struct node temp;

    for(j=0;j<size-1;j++){
        for(i=0;i<size-1-j;i++){
            if(strcmp(directroy[i].name,directroy[i +1].name) > 0){

                temp = directroy[i];
                directroy[i] = directroy[i +1];
                directroy[i+1] = temp;
            }
        }
    }

}

void binarySearch(char fValue[], struct node directory[]) {

    int low = 0;
    int high = size - 1;

    while(low <= high) {

        int mid = (low + high) / 2;

        if(strcmp(directory[mid].name, fValue) == 0) {

            printf("NAME: %s",directory[mid].name);
            printf("Contect Number: %d",directory[mid].contactNumber);
            return;
        }
        else if(strcmp(directory[mid].name, fValue) < 0) {

            low = mid + 1;   // search right
        }
        else {

            high = mid - 1;  // search left
        }
    }

    printf("NOT FOUND\n");
}

int main(){

    int i;
    struct node directroy[size];
    char fValue[50];
    
    printf("\n");

    for(i=0;i<size;i++){

        printf("Name: ");
        scanf("%s",directroy[i].name);

        printf("Contact number: ");
        scanf("%d",&directroy[i].contactNumber);
    }

    sortarray(directroy);

    printf("\nsorted directroy \n\n");

    for(i=0;i<size;i++){

        printf("Name: %s \n",directroy[i].name);
        printf("Contact number: %d \n\n",directroy[i].contactNumber);
    }

    printf("\n");

    printf("Enter the name you want to find: ");
    scanf("%s",fValue);

    binarySearch(fValue,directroy);

return 0;

}