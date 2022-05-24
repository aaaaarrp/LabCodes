
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "linked_list.c"

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

    return 0;
}