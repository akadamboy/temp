#include <stdio.h>
#include <stdlib.h>
#define newW(x) (x*)malloc(sizeof(x))

struct Node{
    int data;
    struct Node* next;
};

void push(struct Node** head, int data){
    struct Node* node = newW(struct Node);
    node->data = data;
    node->next = (*head);
    (*head) = node;
}

int pop(struct Node** head){
    if(!(*head)){
        printf("Stack underflow!\n");
        return -1;
    }
    struct Node* first = (*head);
    (*head) = (*head)->next;
    int data = first->data;
    free(first);
    return data;
}

void display(struct Node* head){
    struct Node* itr = head;
    if(!itr) {
        printf("Stack is empty!\n");
        return;
    }
    while (itr){
        printf("%d ", itr->data);
        itr = itr->next;
    }
    if (head) printf("\n");
}

int main(){
    struct Node* head = NULL;
    while (1){
        printf("Enter the choice\n1. Push, 2.Pop, 3.Display, 4. Exit\n");
        int op;
        scanf("%d", &op);
        if(op == 1){
            system("clear");
            printf("enter the value to push: ");
            int tmp;
            scanf("%d", &tmp);
            push(&head, tmp);
            system("clear");
        }else if(op == 2){
            system("clear");
            pop(&head);
        }else if(op == 3){
            system("clear");
            display(head);
        }else if(op == 4){
            break;
        }else break;
    }
}

