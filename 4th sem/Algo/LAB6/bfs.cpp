
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

void bfs_matrix(vector<vector<int>> &adjacency_matrix) {
    vector<bool> visited(adjacency_matrix.size(), false);
    queue<int> que;

    que.push(0);
    cout << "0 ";

    visited[0] = true;

    while(!que.empty()) {
        int top = que.front();
        que.pop();

        for (int i = 0; i < adjacency_matrix[top].size(); ++i) {
            int node = i;
            
            if (adjacency_matrix[top][node] == 0) continue;   //checks for edge
            if (visited[node]) continue;

            visited[node] = true;

            cout << node << " ";
            que.push(node);
        }
    }

    cout << endl;
    cout << endl;
};

void bfs_list(vector<vector<int>> &adjacency_list) {
    vector<bool> visited(adjacency_list.size(), false);
    queue<int> que;

    que.push(0);
    cout << "0 ";

    visited[0] = true;

    while(!que.empty()) {
        int top = que.front();
        que.pop();

        for (int i = 0; i < adjacency_list[top].size(); ++i) {
            int node = adjacency_list[top][i];
            if (visited[node]) continue;
            
            visited[node] = true;
            cout << node << " ";
            que.push(node);
        }
    }

    cout << endl;
    cout << endl;
}

void print_adjacency_matrix(vector<vector<int>> &adjacency_matrix) {
    cout << "       |";
    for (int i = 0; i < adjacency_matrix.size(); ++i) {
        cout << setw(2) << i << " |";
    }
    cout << endl;
    cout << "--------";
    for (int i = 0; i < adjacency_matrix.size(); ++i) {
        cout << "----";
    }
    cout << endl;
    for (int i = 0; i < adjacency_matrix.size(); ++i) {
        cout << " " << setw(4) << i << "  |";

        for (auto j: adjacency_matrix[i]) {
            cout << setw(2) << j << " |";
        }

        cout << endl;
    }

    cout << endl;
    cout << endl;
}

void print_adjacency_list(vector<vector<int> > &adjacency_list) {

    for (int i = 0; i < adjacency_list.size(); ++i) {
        cout << "vertex " << setw(2) << i << " ";

        for (auto j: adjacency_list[i]) {
            cout << " -> " << setw(2) << j;
        }

        cout << endl;
    }
    cout << endl;
    cout << endl;
}

int main(void) {
    clock_t start;
    clock_t end;
    double time_taken;
    double machine_constant;

    cout << "\n------------------- Adjacency matrix -------------------\n" << endl;
    cout << "\n----------- Sparse graph -----------\n" << endl;

    // sparse adjacency matrix
    vector<vector<int>> sparse_adjacency_matrix = {
       //0  1  2  3  4  5  6  7  8  9
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 0
        {0, 0, 1, 1, 1, 0, 1, 0, 0, 0}, // 1
        {0, 1, 0, 1, 0, 1, 0, 0, 0, 0}, // 2
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 3
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 4
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1}, // 5
        {0, 1, 0, 0, 0, 1, 0, 1, 1, 0}, // 6
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, // 7
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 1}, // 8
        {0, 0, 0, 0, 0, 1, 0, 0, 1, 0}, // 9
    };

    print_adjacency_matrix(sparse_adjacency_matrix);

    cout << "BFS => ";
    start = clock();
    bfs_matrix(sparse_adjacency_matrix);    //calculating time for sparse adjacency matrix
    end = clock();

    cout << endl;
    cout << endl;

    time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Time taken in bfs for sparse Graph (adjacency matrix): "
        << (time_taken * 1000)
        << " milliseconds"
        << endl;

    machine_constant = time_taken / sparse_adjacency_matrix.size();

    cout << "Machine constant of bfs for sparse graph (adjacecny matrix) is: "
        << machine_constant
        << endl;


    cout << "\n----------- Dense graph -----------\n" << endl;


    // sparse adjacency matrix
    vector<vector<int>> dense_adjacency_matrix = {
       //0  1  2  3  4  5  6  7  8  9
        {0, 1, 1, 1, 0, 1, 1, 1, 1, 0}, // 0
        {1, 0, 1, 1, 1, 0, 1, 0, 1, 1}, // 1
        {1, 1, 0, 1, 1, 1, 0, 1, 1, 1}, // 2
        {1, 1, 1, 0, 1, 0, 1, 0, 1, 1}, // 3
        {0, 1, 1, 1, 0, 1, 1, 1, 1, 1}, // 4
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1}, // 5
        {1, 1, 0, 1, 1, 1, 0, 1, 1, 1}, // 6
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 0}, // 7
        {1, 1, 1, 1, 1, 0, 1, 1, 0, 1}, // 8
        {0, 1, 1, 1, 1, 1, 1, 0, 1, 0}, // 9
    };


    print_adjacency_matrix(dense_adjacency_matrix);
    cout << "bFS => ";
    start = clock();
    bfs_matrix(dense_adjacency_matrix);    //calculating time for dense adjacency matrix
    end = clock();

    cout << endl;
    cout << endl;

    time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Time taken in bfs for dense Graph (adjacency matrix): "
        << (time_taken * 1000)
        << " milliseconds"
        << endl;

    machine_constant = time_taken / dense_adjacency_matrix.size();

    cout << "Machine constant of bfs for dense graph (adjacecny matrix) is: "
        << machine_constant
        << endl;



    cout << "\n-------------------- Adjacency list --------------------\n" << endl;


    cout << "\n----------- Sparse graph -----------\n" << endl;

    // adjacency list
    vector<vector<int>> sparse_adjacency_list {
        {5},
        {2, 3, 4, 6},
        {1, 3, 5},
        {1, 2},
        {1},
        {0, 2, 6, 9},
        {1, 5, 7, 8},
        {6},
        {6, 9},
        {5, 8},
    };

    print_adjacency_list(sparse_adjacency_list);
    cout << "BFS => ";
    start = clock();
    bfs_list(sparse_adjacency_list);  //calculating time for sparse adjacency list
    end = clock();

    cout << endl;
    cout << endl;

    time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Time taken in bfs for sparse Graph (adjacency list): "
        << (time_taken * 1000)
        << " milliseconds"
        << endl;

    machine_constant = time_taken / sparse_adjacency_list.size();

    cout << "Machine constant of bfs for sparse graph (adjacecny list) is: "
        << machine_constant
        << endl;



    cout << "\n----------- Dense graph -----------\n" << endl;


    // adjacency list
    vector<vector<int>> dense_adjacency_list {
        {1, 2, 3, 5, 6, 7, 8},
        {0, 2, 3, 4, 6, 8, 9},
        {0, 1, 3, 4, 5, 7, 8, 9},
        {0, 1, 2, 4, 6, 8, 9},
        {1, 2, 3, 5, 6, 7, 8, 9},
        {0, 2, 4, 6, 7, 9},
        {0, 1, 3, 4, 5, 6, 7, 8},
        {0, 2, 4, 5, 6, 8},
        {0, 1, 2, 3, 4, 6, 7, 9},
        {1, 2, 3, 4, 5, 6, 8}
    };

    print_adjacency_list(dense_adjacency_list);
    cout << "BFS => ";
    start = clock();
    bfs_list(dense_adjacency_list); //calculating time for dense adjacency list
    end = clock();

    cout << endl;
    cout << endl;

    time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Time taken in bfs for dense Graph (adjacency list): "
        << (time_taken * 1000)
        << " milliseconds"
        << endl;

    machine_constant = time_taken / dense_adjacency_list.size();

    cout << "Machine constant of bfs for dense graph (adjacecny list) is: "
        << machine_constant
        << endl;

}