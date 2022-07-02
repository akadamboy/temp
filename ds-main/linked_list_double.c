#include <stdio.h>
#include <stdlib.h>
#define newW(x) (x*)malloc(sizeof(x))

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} *tail;

void insert_first(struct Node** head, int data){
    struct Node* node = newW(struct Node);
    node->data = data;
    node->prev = NULL;
    node->next= NULL;
    if(!(*head)){
        (*head) = node;
        return;
    }
    node->next = (*head);
    (*head)->prev = node;
    (*head) = node;
}

int delete_first(struct Node** head){
    int data = -1;
    if(!(*head)){
        printf("list is empty!\n");
        return data;
    }
    struct Node* first = (*head); 
    data = first->data;
    (*head) = (*head)->next;
    free(first);
    if(*head) (*head)->prev = NULL;
    return data;
}

void display(struct Node* head){
    struct Node* itr = head;
    while (itr){
        printf("%d ", itr->data);
        itr = itr->next;
    }
    if(head) printf("\n");
    else printf("List is empty!\n");
}

int main(){
    struct Node* head = NULL;

    while (1){
        printf("Enter the choice\n1. Insert, 2.Delete, 3.Display, 4. Exit\n");
        int op;
        scanf("%d", &op);
        if(op == 1){
            system("clear");
            printf("enter the value to insert: ");
            int tmp;
            scanf("%d", &tmp);
            insert_first(&head, tmp);
            system("clear");
        }else if(op == 2){
            system("clear");
            delete_first(&head);
        }else if(op == 3){
            system("clear");
            display(head);
        }else if(op == 4){
            break;
        }else break;
    }
    return 0;
}


