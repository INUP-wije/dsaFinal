#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int front = -1, rear = -1;
int que[MAX];

int isFull(){
    return (rear + 1) % MAX == front;
}

int isEmpty(){
    return front == -1;
}

void insert(int value){
    if(isFull()){
        printf("Queue is Full\n");
        return;
    }

    if(isEmpty()){
        front = rear = 0;
    }else{
        rear = (rear + 1) % MAX;
    }

    que[rear] = value;
    printf("%d inserted\n", value);
}

int deleteElement(){
    int val;

    if(isEmpty()){
        printf("UnderFlow\n");
        return -1;
    }

    val = que[front];

    if(front == rear){
        front = rear = -1;
    }else{
        front = (front + 1) % MAX;
    }

    printf("%d deleted\n", val);
    return val;
}

int peek(){
    if(isEmpty()){
        printf("Queue is Empty\n");
        return -1;
    }
    return que[front];
}

void display(){
    if(isEmpty()){
        printf("Queue is Empty\n");
        return;
    }

    int i = front;

    printf("Queue elements: ");

    while(1){
        printf("%d ", que[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main(){
    int choice, value;

    while(1){
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                deleteElement();
                break;

            case 3:
                value = peek();
                if(value != -1)
                    printf("Front element: %d\n", value);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}