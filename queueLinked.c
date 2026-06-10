#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct queue{
    struct node *front;
    struct node *rear;
};

void createQueue(struct queue *q){
    q->front = NULL;
    q->rear = NULL;
}

void insert(struct queue *q, int value){
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = NULL;

    if(q->front == NULL){
        q->front = newNode;
        q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("%d inserted into queue\n", value);
}

void deleteElement(struct queue *q){
    struct node *temp;

    if(q->front == NULL){
        printf("Queue Underflow\n");
        return;
    }

    temp = q->front;
    printf("Deleted element: %d\n", temp->data);

    q->front = q->front->next;

    if(q->front == NULL){
        q->rear = NULL;
    }

    free(temp);
}

void display(struct queue *q){
    struct node *temp;

    if(q->front == NULL){
        printf("Queue is Empty\n");
        return;
    }

    temp = q->front;

    printf("Queue elements: ");

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    struct queue q;
    int choice, value;

    createQueue(&q);

    do {
        printf("\n===== QUEUE MENU =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Check if Empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&q, value);
                break;

            case 2:
                deleteElement(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                if (isEmpty(&q)) {
                    printf("Queue is Empty\n");
                } else {
                    printf("Queue is Not Empty\n");
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}