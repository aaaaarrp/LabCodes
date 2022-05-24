
#include <iostream>
#include <map>
#include <ctime>
#include <queue>
using namespace std;
vector<vector<int> > adj;
void addEdge(int x, int y)
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}
void dfs(int start, vector<bool> &visited)
{
    cout << "Visiting " << start << endl;
    visited[start] = true;
    for (int i = 0; i < adj[start].size(); i++)
    {
        if (adj[start][i] == 1 && (!visited[i]))
        {
            dfs(i, visited);
        }
    }
}
int main()
{
    // dense graph
    clock_t start = clock();
    int v = 5;
    int e = 7;
    adj = vector<vector<int> >(v, vector<int>(v, 0));
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    vector<bool> visited(v, false);
    dfs(1, visited);
    clock_t end = clock();
    cout << "Runtime = " << end - start << " Clocks" << endl
         << endl;
    for (auto &i : adj)
    {
        i.clear();
    }
    // sparse graph
    clock_t start2 = clock();
    v = 5;
    e = 3;
    adj = vector<vector<int> >(v, vector<int>(v, 0));
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    vector<bool> visited2(v, false);
    dfs(1, visited2);
    clock_t end2 = clock();
    cout << "Runtime = " << end2 - start2 << " Clocks" << endl;
    return 0;
}