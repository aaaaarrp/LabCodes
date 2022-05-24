#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int val;
    struct node* next;
};

int len(struct node* head) {
    struct node* temp = head;
    int len = 0;

    while(temp != NULL) {
        ++len;
        temp = temp -> next;
    }

    return len;
}

struct node* insert(struct node* head, int val) {
    struct node* new = (struct node*) malloc(sizeof(struct node));

    new -> val = val;
    new -> next = head;
    return new;
}

bool has_node(struct node* head, int val) {
    if (head == NULL) return false;
    return head -> val == val || has_node(head -> next, val);
}

void free_list(struct node* head) {
    if (head == NULL) return;
    free_list(head -> next);
    free(head);
}