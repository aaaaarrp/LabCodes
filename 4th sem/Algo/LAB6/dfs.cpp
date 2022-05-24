
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void dfs_matrix_helper(vector<vector<int>> &adjacency_matrix, vector<bool>& visited, int node) {
    if (visited[node]) return;
    visited[node] = true;
    cout << node << " ";

    //we go through each neighbor of that node 
    for (int i = 0; i < adjacency_matrix[node].size(); ++i) {   
        if (adjacency_matrix[node][i] == 0) continue;   //checks if there is edge or not
        dfs_matrix_helper(adjacency_matrix, visited, i);
    }
}

void dfs_matrix(vector<vector<int>> &adjacency_matrix) {
    vector<bool> visited(adjacency_matrix.size(), false);

    for (int i = 0; i < adjacency_matrix.size(); ++i) {
        if (!visited[i]) {
            dfs_matrix_helper(adjacency_matrix, visited, i);
        }
    }
};

void dfs_list_helper(vector<vector<int>>& adjacency_list, vector<bool>& visited, int node) {
    if (visited[node]) return;
    visited[node] = true;

    cout << node << " ";

    for (int i = 0; i < adjacency_list[node].size(); ++i) {
        dfs_list_helper(adjacency_list, visited, adjacency_list[node][i]);
    }
}

void BFS_list(vector<vector<int>> &adjacency_list) {
    vector<bool> visited(adjacency_list.size(), false);

    for (int i = 0; i < adjacency_list.size(); ++i) {
        if (!visited[i]) {
            dfs_list_helper(adjacency_list, visited, i);
        }
    }
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

void print_adjacency_list(vector<vector<int>> &adjacency_list) {

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
    cout << "DFS => ";
    start = clock();
    dfs_matrix(sparse_adjacency_matrix);
    end = clock();

    cout << endl;
    cout << endl;

    time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Time taken in dfs for sparce Graph (adjacency matrix): "
        << (time_taken * 1000)
        << " milliseconds"
        << endl;

    machine_constant = time_taken / sparse_adjacency_matrix.size();

    cout << "Machine constant of dfs for sparse graph (adjacecny matrix) is: "
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
    cout << "DFS => ";
    start = clock();
    dfs_matrix(dense_adjacency_matrix);
    end = clock();

    cout << endl;
    cout << endl;

    time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Time taken in dfs for dense Graph (adjacency matrix): "
        << (time_taken * 1000)
        << " milliseconds"
        << endl;

    machine_constant = time_taken / dense_adjacency_matrix.size();

    cout << "Machine constant of dfs for dense graph (adjacecny matrix) is: "
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
    BFS_list(sparse_adjacency_list);
    end = clock();

    cout << endl;
    cout << endl;

    time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Time taken in dfs for sparse Graph (adjacency list): "
        << (time_taken * 1000)
        << " milliseconds"
        << endl;

    machine_constant = time_taken / sparse_adjacency_list.size();

    cout << "Machine constant of dfs for sparse graph (adjacecny list) is: "
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
    BFS_list(dense_adjacency_list);
    end = clock();

    cout << endl;
    cout << endl;

    time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Time taken in dfs for dense Graph (adjacency list): "
        << (time_taken * 1000)
        << " milliseconds"
        << endl;

    machine_constant = time_taken / dense_adjacency_list.size();

    cout << "Machine constant of dfs for dense graph (adjacecny list) is: "
        << machine_constant
        << endl;

}