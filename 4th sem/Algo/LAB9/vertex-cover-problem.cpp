// O(V+E)

#include <iostream>
#include <vector>
using namespace std;

class Graph {
    private:
        vector<vector<int> > graph;

    public:
        Graph(int vertex) {
            for (int i = 0; i < vertex; ++i) {
                graph.push_back({});
            }
        }

        void push_edge(int from, int to) {
            if (from >= graph.size() || to >= graph.size()) {
                throw invalid_argument("vertex not present");
            }

            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        int get_vertex() const {
            return graph.size();
        }

        vector<int> get(int node) const {
            if (node >= graph.size()) {
                throw std::invalid_argument("vertex not present");
            }

            return graph[node];
        }

        vector<vector<int>> get_adjacency_list() const {
            return graph;
        }
};

vector<int> vertex_cover(Graph& graph) {
    vector<int> cover;      // list of all the vertex in the vertex cover // initially it will be empty
    vector<bool> visited(graph.get_vertex(), false);      //for checking it's there in vertex cover or not
    for (int i = 0; i < graph.get_vertex(); ++i) {          
        if (visited[i]) continue;       // if visited then we'll pass it

        for (auto node: graph.get(i)) {
            if (visited[node]) continue;           // if its neighbour is visited, we'll pass
                                                    // otherwise edge is not present, we'll add it in vertex cover
            visited[node] = true;
            visited[i] = true;
            break;
        }
    }

    for (int i = 0; i < visited.size(); ++i) {      // to check what vertex are there in vertex cover
        if (!visited[i]) continue;
        cover.push_back(i);         // visited, we'll push it, else pass it
    }

    return cover;
}

int main(void) {
    Graph graph(7);

    graph.push_edge(0, 1);
    graph.push_edge(0, 2);
    graph.push_edge(1, 3);
    graph.push_edge(3, 4);
    graph.push_edge(4, 5);
    graph.push_edge(5, 6);

    auto vertex = vertex_cover(graph);

    cout << "Vertex: ";

    for (auto i: vertex) {
        cout << i << " ";
    }
    
    cout << endl;

    return 0;
}
