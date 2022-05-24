
#include <iostream>
#include<map>
#include<list>
#include<ctime>
using namespace std;
 
class Graph {
 public:
   map< int, bool > visited;
   map< int, list< int > > adj;
 
   void addEdge(int v, int w);
   void DFS(int v);
};
 
void Graph::addEdge(int v, int w) {
   adj[v].push_back(w);
   adj[w].push_back(v);
}
 
void Graph::DFS(int v) {
   visited[v] = true;
   cout << "Visiting " << v << endl;
 
   list< int >::iterator i;
   for (i = adj[v].begin(); i != adj[v].end(); ++i)
       if (!visited[*i])
           DFS(*i);
}
 
int main() {
   clock_t start, finish, start2, finish2;
   Graph g1; // dense graph
 
   start = clock();
 
   g1.addEdge(0, 1);
   g1.addEdge(0, 2);
   g1.addEdge(0, 3);
   g1.addEdge(1, 2);
   g1.addEdge(1, 3);
   g1.addEdge(1, 4);
   g1.addEdge(2, 4);
 
   g1.DFS(1);
 
   finish = clock();
 
   cout << "Runtime = " << (finish - start) << " clocks\n" << endl;
 
   Graph g2; // sparse graph
 
   start2 = clock();
 
   g2.addEdge(0, 1);
   g2.addEdge(0, 2);
   g2.addEdge(1, 3);
 
   g2.DFS(1);
 
   finish2 = clock();
 
   cout << "Runtime = " << (finish2 - start2) << " clocks\n" << endl;
 
   return 0;
}