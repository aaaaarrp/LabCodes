#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge {
    int source;
    int to;
    int weight;

    Edge(): source(-1), to(-1), weight(-1) {}
    Edge(int source, int to, int weight): source(source), to(to), weight(weight) {}

    bool operator() (const Edge& B, const Edge& A) {
        return B.weight > A.weight;
    }
};

class Graph {
    private: 
        vector<vector<Edge>> graph;
        vector<Edge> edges;
        int vertex;

    public: 
        Graph(int vertex): vertex(vertex) {
            for (int i = 0; i < vertex; ++i) {
                this -> graph.push_back({});
            }
        }

        void push_edge(Edge edge) {     // for graph
            if (edge.source >= vertex || edge.to >= vertex) {
                throw invalid_argument("vertex not present");
            }

            Edge e1(edge.source, edge.to, edge.weight);
            Edge e2(edge.to, edge.source, edge.weight);

            this -> graph[edge.source].push_back(e1);
            this -> graph[edge.to].push_back(e2);
            this -> edges.push_back(edge);
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
            return this -> edges;
        }

        vector<vector<Edge>> get_graph() {
            return this -> graph;
        }

};

void add_edge (     //for priority queue
    int vertex,
    vector<bool> &visited,
    Graph& graph,
    priority_queue<Edge, vector<Edge>, Edge>& pq
) {
    visited[vertex] = true;

    vector<Edge> edges = graph.get(vertex);
    for (Edge e: edges) {
        if (!visited[e.to]) {
            pq.push(e);
        }
    }
}

Graph prims_MST(Graph graph) {
    int m = graph.get_vertex();
    int total_edges = 0;

    priority_queue<Edge, vector<Edge>, Edge> pq;
    vector<bool> visited(graph.get_vertex(), false);
    Graph mst(graph.get_vertex());

    add_edge(0, visited, graph, pq);

    while (!pq.empty() && total_edges != m) {
        Edge edge = pq.top();
        pq.pop();

        int node_index = edge.to;

        if (visited[node_index]) continue;
        mst.push_edge(edge);
        add_edge(node_index, visited, graph, pq);
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
        cout << "| " << setw(4) << edge.source << " | " << setw(4) << edge.to << " | " << setw(8) << edge.weight << " |" << endl;
    }

    cout << "'------------------------'" << endl;
    cout << endl;
}

void dense_graph() {
    clock_t start;
    clock_t end;
    double time_taken;
    double machine_constant;
    Graph graph(9);

    graph.push_edge(1, 0, 4);
    graph.push_edge(7, 0, 8);
    graph.push_edge(1, 7, 11);
    graph.push_edge(2, 1, 8);
    graph.push_edge(6, 7, 1);
    graph.push_edge(8, 7, 7);
    graph.push_edge(6, 8, 6);
    graph.push_edge(2, 8, 2);
    graph.push_edge(0, 8, 8);
    graph.push_edge(3, 6, 5);
    graph.push_edge(1, 6, 9);
    graph.push_edge(2, 7, 6);
    graph.push_edge(2, 5, 4);
    graph.push_edge(3, 2, 7);
    graph.push_edge(6, 5, 2);
    graph.push_edge(5, 3, 14);
    graph.push_edge(4, 3, 9);
    graph.push_edge(0, 2, 6);
    graph.push_edge(8, 3, 9);
    graph.push_edge(8, 5, 3);
    graph.push_edge(4, 6, 5);
    graph.push_edge(5, 4, 10);

    print_graph(graph, "Sparse graph");

    start = clock();
    Graph mst = prims_MST(graph);
    end = clock();

    time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Time taken in prims algorithm for dense Graph: "
        << (time_taken * 1000)
        << " milliseconds\n"
        << endl;

    machine_constant = time_taken / (graph.get_edges().size() * log(graph.get_edges().size()));

    cout << "Machine constant prims algorithm for dense graph is: "
        << machine_constant
        << endl;

    print_graph(mst, "Minimum spanning tree");
    auto mst_edges = mst.get_edges();
    int sum = 0;

    for (auto edge: mst_edges) {
        sum += edge.weight;
    }

    cout << "Cost of minimum spanning tree: " << sum << endl;
    cout << endl;
}

void sparse_graph() {
    clock_t start;
    clock_t end;
    double time_taken;
    double machine_constant;
    Graph graph(9);

    graph.push_edge(1, 0, 4);
    graph.push_edge(7, 0, 8);
    graph.push_edge(2, 1, 8);
    graph.push_edge(6, 7, 1);
    graph.push_edge(6, 8, 6);
    graph.push_edge(2, 8, 2);
    graph.push_edge(2, 5, 4);
    graph.push_edge(5, 3, 14);
    graph.push_edge(4, 3, 9);
    graph.push_edge(5, 4, 10);

    print_graph(graph, "Sparse graph");

    start = clock();
    Graph mst1 = prims_MST(graph);
    end = clock();

    time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Time taken in prims algorithm for sparse Graph: "
        << (time_taken * 1000)
        << " milliseconds\n"
        << endl;

    machine_constant = time_taken / (graph.get_edges().size() * log(graph.get_edges().size()));

    cout << "Machine constant prims algorithm for sparse graph: "
        << machine_constant
        << endl;

    print_graph(mst1, "Minimum spanning tree");
    auto mst_edges = mst1.get_edges();
    int sum = 0;

    for (auto edge: mst_edges) {
        sum += edge.weight;
    }

    cout << "Cost of minimum spanning tree: " << sum << endl;
    cout << endl;
}

int main(void) {
    cout << "----------------- Sparse Graph -----------------" << endl;
    sparse_graph();
    cout << "----------------- Dense Graph -----------------" << endl;
    dense_graph();
}