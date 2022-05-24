// Reverse half

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void swap(int* a, int* b);

void reverse(struct Node* head, int n){
    struct Node* p = head;
    struct Node* q = head;
    while(q!= NULL){
        p = p->next;
        q = q->next->next;
    }

    first = head;
    second = 

}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;

}

void printList(struct Node* node){
    while(node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(){
    struct Node* start = NULL;

    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    printList(start);
    reverse(start,7);
    printf("\n");
    printList(start);
}