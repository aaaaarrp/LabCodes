
// Adjacency Matrix

#include <iostream>
#include <vector>

using namespace std;
#define V 6

bool isValidEdge(int u, int v, vector< bool > inMST) {
    if (u == v)
        return false;
    if (inMST[u] == false && inMST[v] == false)
        return false;
    else if (inMST[u] == true && inMST[v] == true)
        return false;
    return true;
}

void primMST(int cost[][V]) {
    vector< bool > inMST(V, false);

    inMST[0]       = true;
    int edge_count = 0, mincost = 0;

    while (edge_count < V - 1) {
        int min = INT_MAX, a = -1, b = -1;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (cost[i][j] < min) {
                    if (isValidEdge(i, j, inMST)) {
                        min = cost[i][j];
                        a   = i;
                        b   = j;
                    }
                }
            }
        }

        if (a != -1 && b != -1) {
            printf("%d - %d\n", a, b);
            edge_count++;

            mincost  = mincost + min;
            inMST[b] = inMST[a] = true;
        }
    }
}

int main() {
    int cost[][V] = { {INT_MAX, 7, INT_MAX, 6, 5, INT_MAX },
                     { 7, INT_MAX, INT_MAX, 2, INT_MAX, 3 },
                     {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 4, INT_MAX },
                     {6, 2, INT_MAX, INT_MAX, INT_MAX, INT_MAX },
                     {5, INT_MAX, 4, INT_MAX, INT_MAX, 1 },
                     {INT_MAX, 3, INT_MAX, INT_MAX, 1, INT_MAX } };

    cout << "MST for Dense Graph:" << endl;

    clock_t start1 = clock();

    primMST(cost);

    clock_t end1 = clock();

    cout << "Machine constant for dense graph: " << end1 - start1 << endl
         << endl;

    int cost2[][V] = {{INT_MAX, 4, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
                      {4, INT_MAX, 2, INT_MAX, INT_MAX, INT_MAX },
                      {INT_MAX, 2, INT_MAX, INT_MAX, 1, INT_MAX },
                      {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 2 },
                      {INT_MAX, INT_MAX, 1, INT_MAX, INT_MAX, 3 },
                      {INT_MAX, INT_MAX, INT_MAX, 2, 3, INT_MAX } };

    cout << "MST for Sparse Graph:" << endl;

    clock_t start2 = clock();

    primMST(cost2);

    clock_t end2 = clock();

    cout << "Machine constant for sparse graph: " << end2 - start2 << endl;

    return 0;
}