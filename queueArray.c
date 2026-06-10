#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

int isEmpty(){
    return rear <front || front==-1 ;
}

int isFill(){
    return rear== MAX -1;
}

void insert(int value){
    if(rear == MAX - 1){
        printf("Queue is Full\n");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = value;
    }
    else{
        rear++;
        queue[rear] = value;
    }
}

int deleteElement(){
    int value;

    if(front == -1 || front > rear){
        printf("Queue is Underflow\n");
        return -1;
    }

    value = queue[front];
    front++;

    if(front > rear){
        front = rear = -1;
    }

    return value;
}

void display(){
    int i;

    if(front == -1){
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");

    for(i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main(){
    int value, choice;

    while(1){
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                value = deleteElement();
                if(value != -1){
                    printf("Deleted element: %d\n", value);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}