#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "UnionFind.cpp"
using namespace std;


struct Edge {
    int from;
    int to;
    int weight;

    bool operator < (const Edge& A) {
        return this -> weight < A.weight;
    }
};

class Graph {
    private: 
        vector<Edge> edges;
        int vertex;

    public: 
        Graph(int vertex): vertex(vertex) {}

        void push_edge(Edge edge) {
            if (edge.from >= vertex || edge.to >= vertex) {
                throw invalid_argument("vertex not present");
            }

            this -> edges.push_back(edge);
        }

        void push_edge(int source, int dest, int weight) {
            if (source >= vertex || dest >= vertex) {
                throw invalid_argument("vertex no present");
            }

            this -> edges.push_back({source, dest, weight});
        }

        int get_vertex() {
            return this -> vertex;
        }

        vector<Edge> get_edges() {
            return this -> edges;
        }

};

Graph kruskal_MST(Graph graph) {
    Graph mst(graph.get_vertex());
    auto edges = graph.get_edges();
    sort(edges.begin(), edges.end());

    UnionFind uf(graph.get_vertex());

    for (auto edge: edges) {
        // if they are already connected then don't push
        // since they will make loop
        if (uf.connected(edge.from, edge.to)) {
            continue;
        }

        // else insert the edge
        uf.unify(edge.from, edge.to);
        mst.push_edge(edge);

        // if component is size is total number of vertex then
        // we have found mst so just break;
        if (uf.size(0) == graph.get_vertex()) {
            break;
        }
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

int main(void) {
    Graph graph(9);

    graph.push_edge(1, 0, 4);
    graph.push_edge(7, 0, 8);
    graph.push_edge(1, 7, 11);
    graph.push_edge(2, 1, 8);
    graph.push_edge(6, 7, 1);
    graph.push_edge(8, 7, 7);
    graph.push_edge(6, 8, 6);
    graph.push_edge(2, 8, 2);
    graph.push_edge(2, 5, 4);
    graph.push_edge(3, 2, 7);
    graph.push_edge(6, 5, 2);
    graph.push_edge(5, 3, 14);
    graph.push_edge(4, 3, 9);
    graph.push_edge(5, 4, 10);

    print_graph(graph, "Original graph");

    Graph mst = kruskal_MST(graph);

    print_graph(mst, "Minimum spanning tree");
    auto mst_edges = mst.get_edges();
    int sum = 0;

    for (auto edge: mst_edges) {
        sum += edge.weight;
    }

    cout << "Cost of minimum spanning tree: " << sum << endl;
    cout << endl;
    return 0;
}
