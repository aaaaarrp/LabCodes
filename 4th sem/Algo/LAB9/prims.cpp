#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

/**
 * @brief Edge class to represent the edge of graph
 * 
 */
struct Edge {
    int from;
    int to;
    int weight;

    Edge(): from(-1), to(-1), weight(-1) {}
    Edge(int from, int to, int weight): from(from), to(to), weight(weight) {}

    bool operator() (const Edge& B, const Edge& A) {
        return B.weight > A.weight;
    }
};


/**
 * @brief Class to store graph as adjacency list
 * 
 */
class Graph {
    private:
        vector<vector<Edge>> graph;
        int vertex;

    public:
        Graph(int vertex): vertex(vertex) {
            for (int i = 0; i < vertex; ++i) {
                this -> graph.push_back({});
            }
        }

        void push_edge(Edge edge) {
            if (edge.from >= vertex || edge.to >= vertex) {
                throw invalid_argument("vertex not present");
            }

            Edge e1(edge.from, edge.to, edge.weight);
            Edge e2(edge.to, edge.from, edge.weight);

            this -> graph[edge.from].push_back(e1);
            this -> graph[edge.to].push_back(e2);
        }

        void push_edge(int source, int dest, int weight) {
            if (source >= vertex || dest >= vertex) {
                throw invalid_argument("vertex no present");
            }

            this -> push_edge({source, dest, weight});
        }

        int get_vertex() {
            return this -> vertex;
        }

        vector<Edge> get(int vertex) {
            return this -> graph[vertex];
        }

        vector<Edge> get_edges() {
            vector<Edge> edges;

            for (int i = 0; i < graph.size(); ++i) {
                for (int j = 0; j < graph[i].size(); ++j) {
                    if (graph[i][j].to > i) continue;
                    Edge e = graph[i][j];
                    edges.push_back(e);
                }
            }

            return edges;
        }

        vector<vector<Edge>> get_graph() {
            return this -> graph;
        }
};

/**
 * @brief Insert all the unvisited edges of graph near vertex
 * 
 * @param vertex edges will be from this vertex
 * @param visited check if vertex is visited or not
 * @param graph input graph
 * @param pq priority-queue for edges to be inserted
 */
void add_edge(int vertex, vector<bool>& visited, Graph& graph, priority_queue<Edge, vector<Edge>, Edge>& pq) {
    visited[vertex] = true;

    vector<Edge> edges = graph.get(vertex);
    for (Edge e: edges) {
        if (!visited[e.to]) {
            pq.push(e);
        }
    }
}

/**
 * @brief Prim's algorithm
 * 
 * @param graph input graph 
 * @return Graph minimum spanning graph from input
 */
Graph prims_MST(Graph graph, int root=0) {
    int m = graph.get_vertex();
    int total_edges = 0;

    priority_queue<
        Edge,
        vector<Edge>,
        Edge
    > pq;

    vector<bool> visited(graph.get_vertex(), false);
    Graph mst(graph.get_vertex());

    add_edge(root, visited, graph, pq);

    while (!pq.empty() && total_edges != m - 1) {
        Edge edge = pq.top();
        pq.pop();

        int node_index = edge.to;

        if (visited[node_index]) continue;

        mst.push_edge(edge);
        total_edges += 1;
        add_edge(node_index, visited, graph, pq);
    }

    if (total_edges != m - 1) {
        throw std::invalid_argument("mst doesn't exist");
    }

    return mst;
}

void print_graph(Graph graph, string s) {
    auto edges = graph.get_edges();

    cout << endl;
    cout << ".------------------------." << endl;
    cout << "| " << setw(22) << s << " |" << endl;
    cout << "|------------------------|" << endl;
    cout << "| Node | Node | Distance |" << endl;

    for (auto edge: edges) {
        cout << "| " << setw(4) << edge.from << " | " << setw(4) << edge.to << " | " << setw(8) << edge.weight << " |" << endl;
    }

    cout << "'------------------------'" << endl;
    cout << endl;
}