#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "queue.c"

void bfs(int **graph, int vertex) {
    bool *visited = (bool *) malloc(sizeof(bool) * vertex);
    for (int i = 0; i < vertex; ++i) visited[i] = false;
    
    struct Queue que = new_queue();
    enqueue(&que, 0);
    printf("0 ");
    visited[0] = true;

    while(!is_empty(&que)) {
        struct Queue p = new_queue();

        while(!is_empty(&que)) {
            int top = front(&que);
            dequeue(&que);

            for (int i = 0; i < vertex; ++i) {
                if (graph[top][i] != 1 || visited[i]) continue;
                visited[i] = true;
                printf("%d ", i);
                enqueue(&p, i);
            }
        }

        que = p;
    }

    free_queue(&que);
    free(visited);
}

int find_sortest(int **graph, int vertex, int start, int end) {
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

            for (int i = 0; i < vertex; ++i) {
                if (graph[top][i] != 1) continue;
                if (i == end) return distance;
                enqueue(&p, i);
            }
        }

        que = p;
    }

    free_queue(&que);
}

void print_graph(int **graph, int vertex) {
    for (int i = 0; i < vertex; ++i) {
        for (int j = 0; j < vertex; ++j) {
            printf("%2d ", graph[i][j]);
        }
        printf("\n");
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

    int** graph = (int **) malloc(sizeof(int *) * vertex);
    for (int i = 0; i < vertex; ++i) {
        int *arr = (int *)malloc(sizeof(int) * vertex);

        for (int j = 0; j < vertex; ++j) {
            arr[j] = g[i][j];
        }

        graph[i] = arr;
    }

    printf("\n\n\nGraph is: \n");
    print_graph(graph, vertex);
    printf("\n\n");

    printf("Printing bfs...\n");
    bfs(graph, vertex);
    printf("\n");
    printf("Shortest distance between %d and %d is: %d\n\n\n", 0, 3, find_sortest(graph, vertex, 0, 3));

    for (int i = 0; i < vertex; ++i) free(graph[i]);
    free(graph);
    return 0;
}