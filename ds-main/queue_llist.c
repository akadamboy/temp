#include <stdio.h>
#include <stdlib.h>
#define newW(x) (x*)malloc(sizeof(x))

struct Node{
    int data;
    struct Node* next;
};

struct Queue{
    struct Node* front;
    struct Node* rear;
};

void enqueue(struct Queue* Q, int data){
    struct Node* node = newW(struct Node);
    if(!node) {
        printf("Queue is full!\n");
        return;
    }
    if(Q->front == NULL){
        Q->rear = node;
        Q->rear->data = data;
        Q->front = Q->rear;
        return;
    }
    node->data = data;
    node->next = NULL;
    Q->rear->next = node;
    Q->rear = Q->rear->next;
}

int dequeue(struct Queue* Q){
    int data = -1;
    if(!Q->front){
        printf("stack underflow!\n");
        return data;
    }
    if(Q->front == Q->rear){
        data = Q->front->data;
        free(Q->front);
        Q->front = Q->rear = NULL;
        return data;
    }
    data = Q->front->data;
    struct Node* first = Q->front;
    Q->front = Q->front->next;
    data = first->data;
    free(first);
    return data;
}

void display(struct Queue* Q){
    struct Node* itr = Q->front;
    while (itr){
        printf("%d ", itr->data);
        itr = itr->next;
    }
    if(Q->front) printf("\n");
    else printf("Queue is empty!\n");
}

int main(){
    struct Queue* queue = newW(struct Queue);
    queue->front = NULL;
    queue->rear = NULL;

    while (1){
        printf("Enter the choice\n1. Enqueue, 2.Dequeue, 3.Display, 4. Exit\n");
        int op;
        scanf("%d", &op);
        if(op == 1){
            system("clear");
            printf("enter the value to push: ");
            int tmp;
            scanf("%d", &tmp);
            enqueue(queue, tmp);
            system("clear");
        }else if(op == 2){
            system("clear");
            dequeue(queue);
        }else if(op == 3){
            system("clear");
            display(queue);
        }else if(op == 4){
            break;
        }else break;
    }
}