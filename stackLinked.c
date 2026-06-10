#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack *next;
};
struct stack *top = NULL;

struct stack *push(struct stack *top,int value){
    struct stack *newNode;
    newNode =(struct stack*)malloc(sizeof(struct stack));

    newNode ->data = value;
    if(top == NULL){
        newNode ->next = NULL;
        top = newNode;
    }else{
        newNode -> next = top;
        top = newNode;
    }
    return top;
}

struct stack *pop(struct stack *top){
    struct stack *tNode;

    tNode = top;
    if (top == NULL){
        printf("stack is UNDERFLOW");
    }else{
    top = top -> next;
    printf("The deleted value is %d\n",tNode -> data);
    free(tNode);    
    }
    return top;
}

int peek(struct stack *top){
   if(top == NULL){
    printf("stack is Empty");
    return -1;
   }else{
    return top -> data;
   }
  
}

void display(struct stack *top){
    struct stack *tNode;
    tNode = top;
    if(tNode == NULL){
        printf("Stack is empty\n");
        return;
    }
    while(tNode != NULL){
        printf("%d ",tNode -> data);
        tNode = tNode -> next;
    }
    printf("\n");
}

int main(){
    int value,choice;

    while(1){
        printf("Enter your choice\n");
        printf("1.push \n2.pop \n3.peek \n4.display \n5.exit\n");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
            printf("Enter the value: ");
            scanf("%d",&value);

            top = push(top,value);
            break;

            case 2:
            top = pop(top);
            break;

            case 3:
            value = peek(top);
            printf("Top value is %d \n",value);
            break;

            case 4:
            display(top);
            break;

            case 5:
            printf("exitting\n");
            exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
return 0;
}