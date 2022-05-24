
#include <iostream>
#include <list>
using namespace std;
class Graph {
    int V;
    list< int > *adj;

  public:
    Graph(int V);

    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj     = new list< int >[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::BFS(int s) {
    bool *visited = new bool[V];

    for (int i = 0; i < V; i++)
        visited[i] = false;

    list< int > queue;

    visited[s] = true;
    queue.push_back(s);

    list< int >::iterator i;

    while (!queue.empty()) {
        s = queue.front();
        cout << "Visitng " << s << endl;

        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
int main() {
    Graph g1(5); // dense graph

    clock_t start = clock();

    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(1, 4);
    g1.addEdge(2, 4);

    g1.BFS(1);

    clock_t end = clock();

    cout << "Runtime = " << end - start << " clocks" << endl << endl;

    Graph g2(5); // sparse graph

    clock_t start2 = clock();

    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 3);

    g2.BFS(1);

    clock_t end2 = clock();

    cout << "Runtime = " << end2 - start2 << " clocks" << endl << endl;
    return 0;
}