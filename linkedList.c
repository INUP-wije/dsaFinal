#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;

struct node *insertBeg(struct node *head,int value){
    struct node *newNode;

    newNode=(struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = head;

    head = newNode;
    return head;
}

struct node *insertEnd(struct node *head,int value){
    struct node *newNode,*findNode;

    newNode =(struct node*)malloc(sizeof(struct node));
    findNode = head;

    newNode->data = value;
    newNode->next = NULL;
    while(findNode->next !=NULL){
        findNode=findNode->next;
    }
    findNode->next = newNode;

    return head;
}


struct node *insertBefor(struct node *head,int value,int hisValue){
    struct node *newNode,*previous,*current;

    newNode=(struct node*)malloc(sizeof(struct node));

    current=head;
    
    while(current->data != hisValue){
        previous=current;
        current =current->next;
    }
    previous->next = newNode;
    newNode->data =value;
    newNode->next = current;

    return head;
}

struct node *insertAfter(struct node *head,int value,int hisValue){
    struct node *newNode,*current;

    newNode=(struct node*)malloc(sizeof(struct node));
    
    current=head;
    while(current ->data!=hisValue){
        current = current->next;
        
    }
    newNode->next=current->next;
    current->next=newNode;

    return 0;
}

struct node *display(struct node *head){
    struct node *ptr;
    
    ptr=head;
    while(ptr !=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return head;
}

struct node *deleteBeg(struct node *head){
    struct node *ptr;
    ptr=head;

    head=head->next;
    free(ptr);
    return head;
}

struct node *deleteLast(struct node *head){
    struct node *ptr,*preptr;

    ptr = head;
    
    while(ptr ->next != NULL){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return head;
}

int main(){
    int choice, value, afterValue;

    do{
        printf("\n\n--- Linked List Menu ---\n");
        printf("1. Insert Beginning\n");
        printf("2. Insert End\n");
        printf("3. Insert Before\n");
        printf("4. Insert After\n");
        printf("5. Delete Beginning\n");
        printf("6. Delete Last\n");
        printf("7. Display\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertBeg(head, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertEnd(head, value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Insert before value: ");
                scanf("%d", &afterValue);
                head = insertBefor(head, value, afterValue);
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Insert after value: ");
                scanf("%d", &afterValue);
                head = insertAfter(head, value, afterValue);
                break;

            case 5:
                head = deleteBeg(head);
                break;

            case 6:
                head = deleteLast(head);
                break;

            case 7:
                head = display(head);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    }while(choice != 0);

    return 0;
}