#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void dfs_helper(int **graph, bool *visited, int* arrival, int* departure, int vertex, int node, int* time) {
    if (visited[node]) return;
    visited[node] = true;
    printf("%d ", node);
    arrival[node] = (*time)++;
    for (int i = 0; i < vertex; ++i) {
        if (graph[node][i] != 1) continue;
        dfs_helper(graph, visited, arrival, departure,vertex, i, time);
    }
    departure[node] = (*time)++;
}

void dfs(int **graph, int vertex, int* arrival, int* departure) {
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

bool has_loop_helper(int **graph, bool* visited, int vertex, int node, int prev) {
    if (visited[node]) return true;
    visited[node] = true;

    for (int i = 0; i < vertex; ++i) {
        if (i != prev && graph[node][i] == 1) {
            if (visited[i] || has_loop_helper(graph, visited, vertex, i, node)) {
                return true;
            }
        }
    }
    return false;
}

bool has_loop(int **graph, int vertex) {
    bool* visited = (bool *) malloc(sizeof(bool) * vertex);
    for (int i = 0; i < vertex; ++i) visited[i] = false;
    visited[0] = true;

    for (int i = 0; i < vertex; ++i) {
        if (graph[0][i] == 1) {
            if (visited[i] || has_loop_helper(graph, visited, vertex, i, 0)) {
                return true;
            }
        }
    }

    free(visited);
    return false;
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

    int *arrival = (int*) malloc(sizeof(int) * vertex);
    int *departure = (int*) malloc(sizeof(int) * vertex);
    printf("\n\n\nGraph is: \n");
    print_graph(graph, vertex);
    printf("\n\n");

    printf("Printing graph by dfs...\n");
    dfs(graph, vertex, arrival, departure);
    printf("\n");
    printf("\nArrival and departure time of the node are...\n");
    for (int i = 0; i < vertex; ++i) printf("Node: %2d\tArrival: %2d\tDeparture: %2d\n", i, arrival[i], departure[i]);
    
    printf("Graph has loop: %s\n\n\n", has_loop(graph, vertex) == true ? "True" : "False");

    free(arrival);
    free(departure);
    for (int i = 0; i < vertex; ++i) free(graph[i]);
    free(graph);
    return 0;
}