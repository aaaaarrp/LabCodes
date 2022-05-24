#include<bits/stdc++.h>
using namespace std;

void first_fit(vector<int>& memory_blocks, vector<int>& processes){
    cout << endl;
    cout << "First Fit :" << endl;
    cout << endl;
    cout << setw(4) << "Order" << setw(12) << "Processes" << setw(16) << "Memory_blocks" << "\n\n";

    vector<int> allocation(processes.size(), -1);

    for(int i=0; i<processes.size(); ++i){
        for(int j=0; j<memory_blocks.size(); ++j){
            if(memory_blocks[j] < processes[i])
                continue;
            allocation[i] = j;
            memory_blocks[j] -= processes[i];
            break;
        }
    }
    for(int i=0; i<processes.size(); i++){
        cout << setw(4) << i+1 << setw(12) << processes[i] << "k" << setw(16);
        if(allocation[i] == -1)
            cout << "Not Allocated";
        else{
            cout << allocation[i]+1;
        }
        cout << endl;
    }
    cout << endl;
}

void best_fit(vector<int>& memory_blocks, vector<int>& processes){
    cout << endl;
    cout << "Best Fit :" << endl;
    cout << endl;
    cout << setw(4) << "Order" << setw(12) << "Processes" << setw(16) << "Memory_blocks" << "\n\n";
}

void worst_fit(vector<int>& memory_blocks, vector<int>& processes){
    cout << endl;
    cout << "Worst Fit :" << endl;
    cout << endl;
    cout << setw(4) << "Order" << setw(12) << "Processes" << setw(16) << "Memory_blocks" << "\n\n";
}

int main() {
    vector<int> memory_blocks = {100, 450, 250, 300, 600};
    vector<int> processes = {212, 317, 172, 426};

    first_fit(memory_blocks, processes);
    best_fit(memory_blocks, processes);
    worst_fit(memory_blocks, processes);
}