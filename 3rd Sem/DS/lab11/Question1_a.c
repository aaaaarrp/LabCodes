#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool is_path_helper(int **graph, bool* visited, int vertex, int start, int end) {
    if (visited[start]) return false;
    if (graph[start][end] == 1) return true;
    visited[start] = true;

    for (int i = 0; i < vertex; ++i) {
        if (graph[start][i] != 1) continue;

        if (is_path_helper(graph, visited, vertex, i, end)) {
            return true;
        }
    }

    return false;
} 

bool is_path(int **graph, int vertex, int start, int end) {
    bool* visited = (bool *) malloc(sizeof(bool) * vertex);
    for (int i = 0; i < vertex; ++i) visited[i] = false;
    bool ans = is_path_helper(graph, visited, vertex, start, end);
    free(visited);
    return ans;
}

bool is_complete_graph(int** graph, int vertex) {
    for (int i = 0; i < vertex; ++i) {
        for (int j = 0; j < vertex; ++j) {
            if (graph[i][j] != 1 && i != j) {
                return false;
            }
        }
    }
    
    return true;
};

int indegree_of_node(int **graph, int vertex, int node) {
    int degree = 0;
    for (int i = 0; i < vertex; ++i) {
        if (graph[node][i] == 1) ++degree;
    }
    return degree;
}

int outdegree_of_node(int **graph, int vertex, int node) {
    int degree = 0;
    for (int i = 0; i < vertex; ++i) {
        if (graph[i][node] == 1) ++degree;
    }
    return degree;
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
        for (int j = 0; j < vertex; ++j) arr[j] = g[i][j];
        graph[i] = arr;
    }
    printf("\n\n\nGraph is: \n");
    print_graph(graph, vertex);
    printf("\n\n");

    printf("is complete graph: %s\n", is_complete_graph(graph, vertex) == true ? "True" : "False");
    printf("is path between node %d and %d: %s\n", 0, 5, is_path(graph, vertex, 0, 5) == true ? "True" : "False");
    printf("Out_degree of node %d is: %d\n", 1, outdegree_of_node(graph, vertex, 1));
    printf("In_degree of node %d is: %d\n\n\n", 1, indegree_of_node(graph, vertex, 1));
    for (int i = 0; i < vertex; ++i) free(graph[i]);
    free(graph);
    return 0;
}