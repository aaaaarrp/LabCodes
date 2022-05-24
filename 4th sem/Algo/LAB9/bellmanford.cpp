
//Time: O(VE)
#include <bits/stdc++.h>
using namespace std;

void bellmanFord(int graph[][3], int v, int e, int source){
    
    int dis[v];
    for(int i=0; i<v; i++)  // Initialize distance of all vertices as infinite.
        dis[i] = INT_MAX;

    dis[source] = 0;    // initialize distance of source as 0

    for(int i=0; i<v-1; i++){   // Relaxation of all edges |V| - 1 times.
        for(int j=0; j<e; j++){
            if(dis[graph[j][0]] != INT_MAX && dis[graph[j][0]]+graph[j][2] < dis[graph[j][2]])
                dis[graph[j][1]] = dis[graph[j][0]]+graph[j][2];
        }
    }

    for(int i=0; i<e; i++){  // check for negative-weight cycles. If we get a
                                    // shorter path, then there is a cycle.
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
        if(dis[x] != INT_MAX && dis[x]+weight < dis[y])
            cout << "Graph contains Negative weighted cycle" << endl;
    }

    cout << "Vertex - Distance from Source" << endl;
    for(int i=0; i < v; i++)
        cout << i << "\t\t" << dis[i] << endl;
}


int main(){
    int V = 5;
    int E = 8; 
    int graph[][3] = { { 0, 1, -1 }, { 0, 2, 4 },
                       { 1, 2, 3 }, { 1, 3, 2 },
                       { 1, 4, 2 }, { 3, 2, 5 },
                       { 3, 1, 1 }, { 4, 3, -3 } };
    
    bellmanFord(graph, V, E, 0);
    return 0;
}