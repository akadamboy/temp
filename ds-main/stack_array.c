#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    int* arr;
};

void display(struct Stack* stack){
    for(int i = stack->top; i>=0; i--)
        printf("%d ", stack->arr[i]);
    printf("\n");
}

void push(struct Stack* stack, int data){
    if(stack->top >= stack->size-1){
        printf("stack overflow!\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = data;
}

int pop(struct Stack* stack){
    if(stack->top < 0){
        printf("stack underflow!\n");
        return -1;
    }
    int x = stack->arr[stack->top];
    stack->arr[stack->top] = 0;
    stack->top--;
    return x;
}

int main(){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = 5;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->size * sizeof(int));

    while (1){
        printf("Enter the choice\n1. Push, 2.Pop, 3.Display, 4. Exit\n");
        int op;
        scanf("%d", &op);
        if(op == 1){
            system("clear");
            printf("enter the value to push: ");
            int tmp;
            scanf("%d", &tmp);
            push(stack, tmp);
            system("clear");
        }else if(op == 2){
            system("clear");
            pop(stack);
        }else if(op == 3){
            system("clear");
            display(stack);
        }else if(op == 4){
            break;
        }else break;
    }
    return 0;
}

