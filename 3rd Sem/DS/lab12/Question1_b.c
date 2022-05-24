#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "queue.c"
#include "linked_list.c"

void bfs(struct node **graph, int vertex) {
    bool *visited = (bool *) malloc(sizeof(bool) * vertex);
    for (int i = 0; i < vertex; ++i) visited[i] = false;
    
    struct Queue que = new_queue();
    enqueue(&que, 0);
    printf("0 ");
    visited[0] = true;

    while(!is_empty(&que)) {

        int top = front(&que);
        dequeue(&que);

        struct node* head = graph[top];

        while (head != NULL) {
            int node = head -> val;
            head = head -> next;
            if (visited[node]) continue;

            visited[node] = true;
            printf("%d ", node);

            enqueue(&que, node);
        }

    }

    free_queue(&que);
    free(visited);
}

int find_sortest(struct node **graph, int vertex, int start, int end) {
    bool *visited = (bool *) malloc(sizeof(bool) * vertex);
    for (int i = 0; i < vertex; ++i) visited[i] = false;
    
    struct Queue que = new_queue();
    enqueue(&que, start);
    int distance = 0;

    while(!is_empty(&que)) {
        struct Queue p = new_queue();
        ++distance;

        while(!is_empty(&que)) {
            int top = front(&que);
            dequeue(&que);

            struct node* head = graph[top];

            while (head != NULL) {
                int node = head -> val;
                head = head -> next;
                if (visited[node]) continue;
                if (node == end) return distance;
                visited[node] = true;
                enqueue(&p, node);
            }
        }

        que = p;
    }

    free_queue(&que);
    free(visited);
}

void print_graph(struct node **graph, int vertex) {
    for (int i = 0; i < vertex; ++i) {
        struct node* head = graph[i];

        printf("%d ---> ", i);
        while (head != NULL) {
            printf("%3d ->", head -> val);
            head = head -> next;
        }

        printf(" NULL\n");
    }
}

int main(void) {
    int vertex = 6;

    int g[][6] = {
        {0, 1, 1, 0, 1, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    struct node **graph = (struct node**) malloc(sizeof(struct node*) * vertex);

    for (int i = 0; i < vertex; ++i) {
        struct node* head = NULL;
    
        for (int j = 0; j < vertex; ++j) {
            if (g[i][j] != 1) continue;
            head = insert(head, j);
        }

        graph[i] = head;
    }

    printf("\n\nGraph is : \n");
    print_graph(graph, vertex);
    printf("\n\n");

    printf("Printing bfs...\n");
    bfs(graph, vertex);
    printf("\n");
    printf("Shortest distance between %d and %d is: %d\n\n\n", 0, 3, find_sortest(graph, vertex, 0, 3));

    for (int i = 0; i < vertex; ++i) {
        free_list(graph[i]);
    }
    free(graph);
    return 0;
}