#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "linked_list.c"

bool is_path_helper(struct node **graph, bool* visited, int start, int end) {
    if (visited[start]) return false;
    if (has_node(graph[start], end)) return true;
    visited[start] = true;

    struct node* head = graph[start];

    while(head != NULL) {
        int i = head -> val;

        if (is_path_helper(graph, visited, i, end)) {
            return true;
        }

        head = head -> next;
    }

    return false;
} 

bool is_path(struct node **graph, int vertex, int start, int end) {
    bool* visited = (bool *) malloc(sizeof(bool) * vertex);
    for (int i = 0; i < vertex; ++i) visited[i] = false;
    bool ans = is_path_helper(graph, visited, start, end);
    free(visited);
    return ans;
}

bool is_complete_graph(struct node **graph, int vertex) {
    bool* visited = (bool *) malloc(sizeof(bool) * vertex);
    
    for (int i = 0; i < vertex; ++i) {
        for (int j = 0; j < vertex; ++j) visited[j] = false;

        struct node* head = graph[i];

        while(head != NULL) {
            visited[head -> val] = true;
            head = head -> next;
        }

        for (int j = 0; j < vertex; ++j) {
            if (!visited[i] && j != i) {
                return false;
            }
        }
    }
    free(visited);
    return true;
};


int indegree_of_node(struct node **graph, int vertex, int node) {
    int degree = 0;
    for (int i = 0; i < vertex; ++i) {
        if (has_node(graph[i], node)) {
            ++degree;
        }
    }
    return degree;
}

int outdegree_of_node(struct node **graph, int vertex, int node) { 
    return len(graph[node]);
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

    printf("\n\n\nGraph is : \n");
    print_graph(graph, vertex);
    printf("\n\n");

    printf("is complete graph: %s\n", is_complete_graph(graph, vertex) == true ? "True" : "False");
    printf("is path between node %d and %d: %s\n", 0, 5, is_path(graph, vertex, 0, 5) == true ? "True" : "False");
    printf("Out_degree of node %d is: %d\n", 1, outdegree_of_node(graph, vertex, 1));
    printf("In_degree of node %d is: %d\n\n\n", 1, indegree_of_node(graph, vertex, 1));

    for (int i = 0; i < vertex; ++i) {
        free_list(graph[i]);
    }
    free(graph);
    return 0;
}