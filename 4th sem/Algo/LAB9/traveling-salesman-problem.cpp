
// time: ElogV

#include <iostream>
#include <vector>
#include "prims.cpp"
using namespace std;

/**
 * 
 * Algorithm
 * 
 * approximation using assumption
 * distance[i, j] <= distance[i, k] + dist[k, j] (triangle-inquality)
 * 
 * convert the graph to minimum
 * spanning tree (prims) with start-node being the root
 * 
 * DFS with the start-node
 * 
 */

void dfs(Graph& graph, int node, vector<bool>& visited, vector<int>& path) {
    path.push_back(node);
    visited[node] = true;

    auto edges = graph.get(node);

    for (auto edge: edges) {
        if (!visited[edge.to]) {
            dfs(graph, edge.to, visited, path);
            path.push_back(node);
        }
    }
}

vector<int> travelling_salesman(Graph graph, int start) {
    Graph mst = prims_MST(graph, start);

    print_graph(mst, "MST");

    vector<bool> visited(graph.get_vertex(), false);
    vector<int> path;

    dfs(mst, start, visited, path);

    return path;
}

int main(void) {
    int start = 0;
    Graph graph(5);

    // input graph
    graph.push_edge(0, 1, 10);
    graph.push_edge(0, 2, 18);
    graph.push_edge(0, 3, 40);
    graph.push_edge(0, 4, 20);
    graph.push_edge(1, 2, 35);
    graph.push_edge(1, 3, 15);
    graph.push_edge(1, 4, 12);
    graph.push_edge(2, 3, 10);
    graph.push_edge(2, 4, 25);
    graph.push_edge(3, 4, 30);

    print_graph(graph, "Input graph");

    auto path = travelling_salesman(graph, start);

    cout << "Path: ";

    for (int i = 0; i < path.size() - 1; ++i) {
        cout << path[i] << " -> ";
    }

    cout << path[path.size() - 1] << endl;
    return 0;
}
