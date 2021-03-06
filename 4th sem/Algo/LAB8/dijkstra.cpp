
// A C++ program for Dijkstra's single source shortest path algorithm. 
// Time: O(V^2)-adjacency matrix  //  Time: O(ElogV)

#include <bits/stdc++.h>
using namespace std;

#define V 9 //number of vertices

// function to find the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree
int minDistance(int distance[], bool sptSet[]){
    // Initialize min value
    int min = INT_MAX, min_index;
    for(int v=0; v < V; v++){
        if(sptSet[v] == false && distance[v] <= min){
            min = distance[v];
            min_index = v;
        }
    }

    return min_index;
}

// function to print the constructed distance array
void printGraph(int distance[]){
    cout << "Vertex\tDistance from the source" << endl;
    for(int i=0; i < V; i++){
        cout << i << "\t\t" << distance[i] << endl;
    }
}

// Function that implements Dijkstra's single source shortest path algorithm for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int source){
    int distance[V];    // The output array.  distance[i] will hold the shortest distance from src to i
    bool sptSet[V];     // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized

    // Initializing all distances as INFINITE and stpSet[] as false
    for(int i=0; i < V; i++){
        distance[i] = INT_MAX,
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    distance[source] = 0;

    // Find shortest path for all vertices
    for(int count=0; count < V-1; count++){
        // Pick the minimum distance vertex from the set of vertices not yet processed. u is always equal to src in the first iteration.
        int u = minDistance(distance, sptSet);
        // Mark the picked vertex as processed
        sptSet[u] = true;
        // Update dist value of the adjacent vertices of the picked vertex.
        for(int v=0; v < V; v++){
            // Update distance[v] only if is not in sptSet, there is an edge from u to v,
            // and total weight of path from src to  v through u is smaller than current value of dist[v]
            if(!sptSet[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
                distance[v] = distance[u] + graph[u][v];
        }
    }

    printGraph(distance);

}

int main()
{
   
    //input taken as adjacency matrix
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    dijkstra(graph, 0);
 
    return 0;
}