#include <iostream>
#include <iomanip>
#include <vector>
//#include <algorithm>
#include <queue>
using namespace std;

struct Process {
    string name;
    int burst_time;
    int arrival_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;

    bool operator< (const Process& A) {
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
    cout << "┌────────────────┬───────────────────┬─────────────────┬──────────────────┬────────────────────┐" << endl;
    cout << "│  Process Name  │   Arrival time    │   Burst time    │   Waiting time   │  Turn around time  │" << endl;
    cout << "├────────────────┼───────────────────┼─────────────────┼──────────────────┼────────────────────┤" << endl;

    for (auto process: processes) {
        cout << "│  " 
            << setw(12) << process.name << "  │" 
            << setw(17) << process.arrival_time << "  │" 
            << setw(15) << process.burst_time << "  │"
            << setw(16) << process.waiting_time << "  │"
            << setw(18) << process.turn_around_time << "  │" << endl;
        
        waiting_time += process.waiting_time;
        turn_around_time += process.turn_around_time;
    }

    cout << "└────────────────┴───────────────────┴─────────────────┴──────────────────┴────────────────────┘" << endl;
    cout << endl;
    cout << "Average waiting time: " << waiting_time / processes.size() << endl;
    cout << "Average turn around time: " << turn_around_time / processes.size() << endl;
    cout << "Total Idle time of the processor: " << idle_time << endl;
    cout << endl;
}

void round_robin(vector<Process>& processes, const int time_quantum = 2) {
    //sort(processes.begin(), processes.end());
    Sort(processes);
    vector<Process> completed = processes;
    vector<bool> process_is_in_queue(processes.size(), false);
    queue<int> ready_queue;
    int idle_time = 0; 

    int time = processes[0].arrival_time;
    ready_queue.push(0);
    process_is_in_queue[0] = true;
    idle_time = time;

    while (!ready_queue.empty()) {
        int index = ready_queue.front();
        ready_queue.pop();
        process_is_in_queue[index] = false;

        if (processes[index].burst_time > time_quantum) {
            time += time_quantum;
            processes[index].burst_time -= time_quantum;
        } else {
            time += processes[index].burst_time;
            processes[index].burst_time = 0;

            cout << processes[index].name << " " << time << endl;

            completed[index].completion_time = time;
            completed[index].turn_around_time = completed[index].completion_time - completed[index].arrival_time;
            completed[index].waiting_time = completed[index].turn_around_time - completed[index].burst_time;
        }

        for (int i = 0; i < processes.size(); ++i) {
            if (process_is_in_queue[i] || i == index) continue;
            if (processes[i].burst_time == 0) continue;
            if (processes[i].arrival_time > time) continue;

            ready_queue.push(i);
            process_is_in_queue[i] = true;
        }

        if (processes[index].burst_time > 0) {
            ready_queue.push(index);
            process_is_in_queue[index] = true;
        }

        if (ready_queue.empty()) {
            bool is_completed = true;

            for (auto process: processes) {
                if (process.burst_time != 0) {
                    is_completed = false;
                    break;
                }
            }

            if (!is_completed) {
                int min_arrival_time = INT32_MAX;
                int min_arrival_time_index = -1;
                
                for (int i = 0; i < processes.size(); ++i) {
                    if (processes[i].arrival_time > time && processes[i].burst_time > 0) {
                        min_arrival_time = min(min_arrival_time, processes[i].arrival_time);
                        min_arrival_time_index = i;
                    }
                }

                idle_time += (min_arrival_time - time);
                time = min_arrival_time;
                process_is_in_queue[min_arrival_time_index] = true;
                ready_queue.push(min_arrival_time_index);
            }
        }
    }

    print_processes(completed, idle_time);
}

int main(void) {
    vector<Process> processes = {
        {"P1", 12, 2},
        {"P2", 2, 0},
        {"P3", 3, 1},
        {"P4", 7, 3},
        {"P5", 11, 5}
    };

    round_robin(processes);
}