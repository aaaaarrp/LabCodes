//adjacency matrix

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isCompleteGraph(int **graph, int vertex){
    for(int i=0; i < vertex; ++i){
        for(int j = 0; j < vertex; ++j){
            if(graph[i][j] != 1 && i != j)
                return false;
        }
    }
    return true;
}

void printGraph(int **graph, int vertex){
    for(int i = 0; i < vertex; ++i){
        for(int j = 0; j < vertex; ++j){
            printf("%2d",graph [i][j]);
        }
        printf("\n");
    }
}

int main(){
    int vertex = 4;
    int g[][4] = {
        {0,1,1,1},
        {1,0,1,1},
        {1,1,0,1},
        {1,1,1,0},
    };

    int ** graph = (int **)malloc(sizeof(int *)*vertex);
    for(int i = 0; i < vertex; ++i){
        int *arr = (int *)malloc(sizeof(int*)*vertex);
        for(int j = 0; j < vertex; ++j){
            arr[j] = g[i][j];
            graph[i] = arr;
        }
    }

    printf("\nGraph is: \n");
    printGraph(graph, vertex);
    printf("\n");
    printf("is Complete graph: %s",isCompleteGraph(graph, vertex) == true? "True":"False");

    return 0;
}