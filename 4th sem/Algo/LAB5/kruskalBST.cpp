
// Implementing Kruskal's algorithm for finding MST

#include <iostream>
#include <vector>
using namespace std;
// unionFind data structure
// path compression + rank by union

class unionFind {
	int* parent;
	int* rank;

public:
	unionFind(int n)
	{
		parent = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	// Find function
	int find(int i)
	{
		if (parent[i] == -1)
			return i;

		return parent[i] = find(parent[i]);
	}
	// union function 
	void unite(int source, int destination)
	{
		int s1 = find(source);
		int s2 = find(destination);

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};

class Graph {
	vector<vector<int> > edgelist;
	int V;

public:
	Graph(int V) { this->V = V; }

	void addEdge(int source, int destination, int weight)
	{
		edgelist.push_back({ weight, source, destination });
	}

	void kruskals_mst()
	{
		// 1. Sort all edges
		sort(edgelist.begin(), edgelist.end());

		// Initialize the unionFind
		unionFind s(V);
		int ans = 0;
		cout << "Following are the edges in the "
				"constructed MST"
			<< endl;
		//for (vector<int> edge : edgelist) {
            for(int i=0; i < edgelist.size(); i++){
                vector< int> edge = edgelist.at(i);
			    int weight = edge[0];
			    int source = edge[1];
			    int destination = edge[2];

			// take that edge in MST if it does form a cycle
			    if (s.find(source) != s.find(destination)) {
				        s.unite(source, destination);
				        ans += weight;
				        cout << source << " -- " << destination << " == " << weight << endl;
			}
		}
		cout << "Minimum Cost Spanning Tree: " << ans << endl;
	}
};
int main()
{
	/* Let us create following weighted graph
				10
			0--------1
			| \	 |
			6| 5\ |15
			|	 \ |
			2--------3
				4	 */
	Graph g(4);
	g.addEdge(0, 1, 10);
	g.addEdge(1, 3, 15);
	g.addEdge(2, 3, 4);
	g.addEdge(2, 0, 6);
	g.addEdge(0, 3, 5);

	// int n, m;
	// cin >> n >> m;

	// Graph g(n);
	// for (int i = 0; i < m; i++)
	// {
	//	 int source, destination, weight;
	//	 cin >> source >> destination >> weight;
	//	 g.addEdge(source, destination, weight);
	// }

	g.kruskals_mst();
	return 0;
}
