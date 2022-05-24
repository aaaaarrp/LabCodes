#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int val;
    struct node* next;
};

struct Queue {
    struct node* head;
    struct node* last;
};

struct Queue new_queue() {
    struct Queue q;
    q.head = NULL;
    q.last = NULL;
    return q;
}

void enqueue(struct Queue* Q, int val) {
    if (Q -> head == NULL) {
        Q -> head = (struct node*) malloc(sizeof(struct node));
        Q -> head -> val = val;
        Q -> head -> next = NULL;
        Q -> last = Q -> head;
        return;
    }

    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node -> val = val;
    new_node -> next = NULL;
    Q -> last -> next = new_node;
    Q -> last = Q -> last -> next;
}

void dequeue(struct Queue* Q) {

    if (Q -> head == NULL) {
        fprintf(stderr, "Queue is empty.\n");
        exit(1);
    }

    struct node* temp = Q -> head;
    Q -> head = Q -> head -> next;

    free(temp);
}

bool is_empty(struct Queue* Q) {
    if (Q -> head == NULL) return true;
    return false;
}

int front(struct Queue* Q) {

    if (Q -> head == NULL) {
        fprintf(stderr, "Queue is empty.\n");
        exit(1);
    }

    return Q -> head -> val;
}

void free_queue(struct Queue* Q) {
    
    struct node* head = Q -> head;
    struct node* temp;

    while (head != NULL) {
        temp = head -> next;
        free(head);
        head = temp;
    }
}
