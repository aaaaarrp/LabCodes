
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#define V 5
using namespace std;
vector<int> adj[V];
int inDeg[V], outDeg[V];

void addEdge(int i, int j)
{
    adj[i].push_back(j);
    adj[j].push_back(i);
}
void sink(){
    for (int i = 0; i < V; i++)
    {
        if(outDeg[i]==0 && inDeg[i]== ((V)-1)){
            cout<<"Vertex "<<i<<" is a Sink"<<endl;
        }
        else{
            cout<<"Vertex "<<i<<" is not a Sink"<<endl;
        }
    }
}
void donor(){
    for (int i = 0; i < V; i++)
    {
        if(outDeg[i]== (V-1) && inDeg[i]==0){
            cout<<"Vertex "<<i<<" is a Donor"<<endl;
        }
        else{
            cout<<"Vertex "<<i<<" is not a Donor"<<endl;
        }
    }
}
int main()
{
    
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    
    for (int i = 0; i < V; i++)
    {
        outDeg[i] = 0;
        inDeg[i] = 0;
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 1; j < adj[i].size(); j++)
        {
            inDeg[adj[i][j]]++;
        }
    }
    for (int i = 0; i < V; i++)
    {
        outDeg[i] = adj[i].size();
    }
    
    for (int i = 0; i < V; i++)
    {
        cout << "For Vertex " << i << " inDegree = " << inDeg[i] << " outDegree = " << outDeg[i] << endl;
    }
    cout<<endl;
    sink();
    cout<<endl;
    donor();
    cout<<endl;

    return 0;
}