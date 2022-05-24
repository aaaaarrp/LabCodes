
#include <bits/stdc++.h>
using namespace std;

vector<int> vertexCover(vector<vector<int> >& graph){
    vector<int> cover;
    vector<bool> visited(graph.size(), false);

    for(int i=0; i<graph.size(); i++){
        if(visited[i])
            continue;
        for(auto node: graph[i]){
            if(visited[node])
                continue;
            visited[node] = true;
            visited[i] = true;
            break;
        }
    }
    for(int i=0; i<visited.size(); i++){
        if(!visited[i])
            continue;
        cover.push_back(i);
    }
    return cover;
}


int main(){
    vector<vector<int> > graph = {
        {1},
        {0, 2, 3},
        {1},
        {1, 4},
        {3, 5, 6, 7},
        {4},
        {4},
        {4}
    };

    vector<int> vertex = vertexCover(graph);
    for(auto i: vertex)
        cout << i << " ";
    
    cout << endl;
    return 0;
}