#include<stdio.h>

#define MAX 10

int array[MAX],top = -1;

int isEmpty(){
    return top==-1;
}

int isFull(){
    return top == MAX -1;
}

void push(int value){
    if(isFull()){
        printf("Stack is overflow");
    }else{
        top++;
        array[top]=value;
    }
}

int pop(){
    int value;
    if(isEmpty()){
        printf("Stack is Empty");
        return -1;
    }else{
        value = array[top];
        top--;
        return value;
    }
}

int peek(){
    int value;
    if(isEmpty()){
        printf("stack is underFlow\n");
        return -1;
    }else{
        return array[top];
    }
}

void display(){
    int i;
    for(i=0;top>i;i++){
        printf("%d ",array[i]);
    }
    printf("");
}


int main(){

    int choice,value;

    while(1){
        printf("Make your choice\n");
        printf("1:pushValue \n2:popValue \n3:peekValue \n4:display \n5:Exti\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter Number: ");
            scanf("%d",&value);
            push(value);
            break;

            case 2:
            value = pop();
            if(value != -1){
                printf("Deleted value is %d \n",value);
            }
            break;

            case 3:
            value = peek();
            if(value != -1){
                printf("Peek value %d \n",value);
            }
            break;

            case 4:
            display();
            break;

            case 5:
            return 0;

            default:
            printf("Invalid choice\n");
            

        }
    }
}
