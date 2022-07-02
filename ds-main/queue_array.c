#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};

void enqueue(struct Queue* Q, int data){
    if((Q->rear+1)%Q->size == Q->front){
        printf("Queue is full!\n");
        return;
    }
    Q->rear = (Q->rear+1)%Q->size;
    Q->arr[(Q->rear+1)%Q->size] = data;
}

int dequeue(struct Queue* q){
    if(q->front == q->rear){
        printf("Queue is empty, dequeue not possible!\n");
        return -1;
    }
    int data = q->arr[q->front];
    q->front = (q->front+1)%q->size;
    return data;
}

void display(struct Queue* q){
    int i = (q->front+1)%q->size;
    while (i != ((q->rear+1)%q->size)){
        i = (i+1)%q->size;
        printf("%d ", q->arr[i]);
    }
    if(q->front == q->rear) printf("Queue is empty!\n");
    else printf("\n");
}

void print_arr(int a[], int n){
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}


int main(){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->size = 5;
    queue->front = queue->rear =0;
    queue->arr = (int*)malloc(sizeof(int)*queue->size);

    while (1){
        printf("Enter the choice\n1. Enqueue, 2.Dequeue, 3.Display, 4. Exit\n");
        int op;
        scanf("%d", &op);
        system("clear");
        if(op == 1){
            // system("clear");
            printf("enter the value to push: ");
            int tmp;
            scanf("%d", &tmp);
            enqueue(queue, tmp);
        }
        else if(op == 2) dequeue(queue);
        else if(op == 3) display(queue);
        else if(op == 4) break;
        else break;
    }
}