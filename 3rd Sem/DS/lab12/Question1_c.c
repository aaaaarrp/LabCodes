#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "linked_list.c"

void dfs_helper(struct node **graph, bool *visited, int* arrival, int* departure, int vertex, int node, int* time) {
    if (visited[node]) return;
    visited[node] = true;
    printf("%d ", node);
    arrival[node] = (*time)++;

    struct node* head = graph[node];

    while (head != NULL) {
        dfs_helper(graph, visited, arrival, departure,vertex, head -> val, time);
        head = head -> next;
    }

    departure[node] = (*time)++;
}

void dfs(struct node **graph, int vertex, int* arrival, int* departure) {
    bool *visited = (bool *) malloc(sizeof(bool) * vertex);
    for (int i = 0; i < vertex; ++i) visited[i] = false;
    int* time = (int *) malloc(sizeof(int));
    *time = 0;

    for (int i = 0; i < vertex; ++i) {
        if (!visited[i])
            dfs_helper(graph, visited, arrival, departure, vertex, i, time);
    }

    free(visited);
}

bool has_loop_helper(struct node **graph, bool* visited, int vertex, int node, int prev) {
    if (visited[node]) return true;
    visited[node] = true;

    struct node* head = graph[node];

    while (head != NULL) {
        int i = head -> val;
        if (i != prev) {
            if (visited[i] || has_loop_helper(graph, visited, vertex, i, node)) {
                return true;
            }
        }
        head = head -> next;
    }

    return false;
}

bool has_loop(struct node **graph, int vertex) {
    bool* visited = (bool *) malloc(sizeof(bool) * vertex);
    for (int i = 0; i < vertex; ++i) visited[i] = false;
    visited[0] = true;

    struct node* head = graph[0];

    while (head != NULL) {
        int i = head -> val;
        if (visited[i] || has_loop_helper(graph, visited, vertex, i, 0)) {
            return true;
        }
        head = head -> next;
    }

    free(visited);
    return false;
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

    int *arrival = (int*) malloc(sizeof(int) * vertex);
    int *departure = (int*) malloc(sizeof(int) * vertex);
    printf("\n\n\nGraph is : \n");
    print_graph(graph, vertex);
    printf("\n\n");
    printf("Printing graph by dfs...\n");
    dfs(graph, vertex, arrival, departure);
    printf("\n");
    printf("\nArrival and departure time of the node are...\n");
    for (int i = 0; i < vertex; ++i) {printf("Node: %2d\tArrival: %2d\tDeparture: %2d\n", i, arrival[i], departure[i]);}
    printf("Graph has loop: %s\n\n\n\n", has_loop(graph, vertex) == true ? "True" : "False");
    free(arrival);
    free(departure);
    for (int i = 0; i < vertex; ++i) {
        free_list(graph[i]);
    }
    free(graph);
    return 0;
}