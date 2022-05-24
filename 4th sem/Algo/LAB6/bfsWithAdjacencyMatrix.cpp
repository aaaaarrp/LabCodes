

#include <iostream>
#include<map>
#include<ctime>
#include<queue>
using namespace std;
 
vector< vector< int > > adj;
 
void addEdge(int x, int y) {
   adj[x][y] = 1;
   adj[y][x] = 1;
}
 
void bfs(int start) {
   vector< bool > visited(adj.size(), false);
   vector< int > q;
 
   q.push_back(start);
   visited[start] = true;
 
   int vis;
 
   while (!q.empty()) {
       vis = q[0];
       cout << "Visiting " << vis << endl;
 
       q.erase(q.begin());
 
       for (int i = 0; i < adj[vis].size(); i++) {
           if (adj[vis][i] == 1 && (!visited[i])) {
               q.push_back(i);
               visited[i] = true;
           }
       }
   }
 
   cout << endl;
}
 
int main() {
   clock_t start = clock();
   int v         = 5; // number of vertices
   adj           = vector< vector< int > >(v, vector< int >(v, 0));
 
   addEdge(0, 1);
   addEdge(0, 2);
   addEdge(1, 3);
   // performing bfs on the graph
   bfs(1);
 
   clock_t end = clock();
 
   cout << "Runtime = " << end - start << " clocks" << endl << endl;
 
   for (auto &x : adj) {
       x.clear();
   }
 
   clock_t start2 = clock();
   int v2         = 5; // number of vertices
   adj            = vector< vector< int > >(v2, vector< int >(v2, 0));
 
   addEdge(0, 1);
   addEdge(0, 2);
   addEdge(0, 3);
   addEdge(1, 2);
   addEdge(1, 3);
   addEdge(1, 4);
   addEdge(2, 4);
   // performing bfs on the graph
   bfs(1);
 
   clock_t end2 = clock();
 
   cout << "Runtime = " << end2 - start2 << " clocks" << endl;
}