
#include <iostream>
#include <iomanip>
#include <vector>
// #include <algorithm>
#include <queue>
using namespace std;

struct Process {
    string name;
    int burst_time;
    int arrival_time;
    int priority;
    int completion_time;
    int turn_around_time;
    int waiting_time;

    bool operator() (const Process& A, const Process& B) {
        return (A.priority > B.priority);
    }

    bool operator < (const Process& A) {
        return (this -> arrival_time < A.arrival_time);
    }
};

void Sort(vector<Process>& processes) {
    bool done = false;
    int offset = 1;

    while (!done) {
        done = true;

        for (int i = 0; i < processes.size() - offset; ++i) {
            if (processes[i].arrival_time > processes[i + 1].arrival_time) {
                swap(processes[i], processes[i + 1]);
                done = false;
            }
        }

        ++offset;
    }   
}

void print_processes(vector<Process>& processes, int idle_time) {
    double waiting_time = 0;
    double turn_around_time = 0;
    cout << endl;
    cout << "┌────────────────┬───────────────────┬─────────────────┬──────────────────┬──────────────────┬────────────────────┐" << endl;
    cout << "│  Process Name  │   Arrival time    │   Burst time    │   Waiting time   │     Priority     │  Turn around time  │" << endl;
    cout << "├────────────────┼───────────────────┼─────────────────┼──────────────────┼──────────────────┼────────────────────┤" << endl;

    for (auto process: processes) {
        cout << "│  " 
            << setw(12) << process.name << "  │" 
            << setw(17) << process.arrival_time << "  │" 
            << setw(15) << process.burst_time << "  │"
            << setw(16) << process.waiting_time << "  │"
            << setw(16) << process.priority << "  │"
            << setw(18) << process.turn_around_time << "  │" << endl;

        waiting_time += process.waiting_time;
        turn_around_time += process.turn_around_time;
    }

    cout << "└────────────────┴───────────────────┴─────────────────┴──────────────────┴──────────────────┴────────────────────┘" << endl;
    cout << endl;
    cout << "Grantt Chart" << endl;
    string top = "┌";
    string bottom = "└";
    for (int i = 0; i < processes.size(); ++i) {
        top += "────────────────";
        bottom += "────────────────";
        if (i != processes.size() - 1) {
            top += "┬";
            bottom += "┴";
        }
    }
    top += "┐";
    bottom += "┘";

    cout << top << endl;
    
    for (int i = 0; i < processes.size(); ++i) {
        cout << "│  " 
            << setw(14) << processes[i].name;
        if (i == processes.size() - 1) {
            cout << "│" << endl;
        }
    }
    cout << bottom << endl;
    cout << 0;
    for (int i = 0; i < processes.size(); ++i) {
        cout << setw(17) 
            << processes[i].completion_time;
    }
    cout << endl;

    cout << "Average waiting time: " << waiting_time / processes.size() << endl;
    cout << "Average turn around time: " << turn_around_time / processes.size() << endl;
    cout << "Idle time: " << idle_time << endl;
    cout << endl;
}

void priority_scheduling(vector<Process>& processes) {
    // sort(processes.begin(), processes.end());
    Sort(processes);
    priority_queue<Process, vector<Process>, Process> pq;
    vector<Process> completed;

    int idle_time = 0;
    int time = processes[0].arrival_time;
    int j = 1;

    pq.push(processes[0]);
    while (j < processes.size() && processes[0].arrival_time == processes[j].arrival_time) {
        pq.push(processes[j]);
        ++j;
    }

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        time += top.burst_time;

        top.completion_time = time;
        top.turn_around_time = top.completion_time - top.arrival_time;
        top.waiting_time = top.turn_around_time - top.burst_time;
        completed.push_back(top);

        for (; j < processes.size(); ++j) {
            if (processes[j].arrival_time <= time) {
                pq.push(processes[j]);
            } else {
                break;
            }
        }

        if (pq.empty() && j != processes.size()) {
            pq.push(processes[j]);
            idle_time += processes[j].arrival_time - time;
            time = processes[j].arrival_time;
        }
    }

    print_processes(completed, idle_time);
}

int main(void) {
    vector<Process> processes = {
        {"P1", 12, 0, 2},
        {"P2", 25, 0, 1},
        {"P3", 13, 0, 3},
        {"P4", 7, 0, 5},
        {"P5", 11, 0, 4}
    };

    priority_scheduling(processes);
}