#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void createList(struct node **head, int n) {
    int i, data;
    struct node *prevNode, *newNode;

    prevNode = NULL;
    newNode  = NULL;

    for (i = 1; i <= n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("Enter the numbers %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (prevNode != NULL)
            prevNode->next = newNode;

        prevNode = newNode;

        if (*head == NULL)
            *head = newNode;
    }

    prevNode->next = *head;

    printf("\nLinked List Created\n");
}

void reverseList(struct node **head) {
    struct node *prev, *cur, *last;

    if (*head == NULL) {
        printf("Cannot reverse empty list.\n");
        return;
    }

    last = *head;

    prev  = *head;
    cur   = (*head)->next;
    *head = (*head)->next;

    while (*head != last) {
        *head     = (*head)->next;
        cur->next = prev;

        prev = cur;
        cur  = *head;
    }

    cur->next = prev;
    *head     = prev;
}


void displayList(struct node *head) {
    struct node *current;
    int n = 1;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    current = head;
    printf("Linked List:\n");

    do {
        printf("%d ", current->data);

        current = current->next;
    } while (current != head);

    printf("\n");
}


int main() {

    int n, choice;

    struct node *head = NULL;

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    createList(&head, n);

    displayList(head);

    printf("\n");

    reverseList(&head);
    printf("List reversed.\n");
    getchar();

    printf("\n");

    displayList(head);

    return 0;
}



