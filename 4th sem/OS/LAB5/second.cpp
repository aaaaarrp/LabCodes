
#include<iostream>
using namespace std;

struct PCB{
    int bt, pid, wt, tat; 
};

int main(){
    struct PCB p[10], temp;
    int i, n, j=1, sum=0, w_total=0, t_total=0;
    float w_avg=0.0, t_avg=0.0;
    cout << "\nEnter the total number of processes: ";
    cin >> n;
    for(i=0; i<n; i++){
        cout << "Enter the burst time of process id" << i+1 << "\n";
        cin >> p[i].bt;
        p[i].pid = i+1;   //incrementing process id
    }
    for(i=0; i<n; i++){    //sorting burst time
        for(j=0; j<n-i-1; j++){
            if(p[j].bt > p[j+1].bt){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    for(i=0; i<n; i++){     // taking wait time & turn around time for each process
        p[i].wt = sum;
        sum = sum+p[i].bt;
        p[i].tat = sum;
    } 
    cout << "\nPID\tWaiting time\tTurnaround time";
    for(i=0; i<n; i++){        //printing values
        cout << "\n" <<p[i].pid << "\t\t" << p[i].wt << "\t\t" << p[i].tat;
        w_total += p[i].wt;
        t_total += p[i].tat;
    }
    w_avg = w_total/(float)n;
    t_avg = t_total/(float)n;
    cout << "\n\nAverage Waiting time:" << w_avg << "\n";
    cout << "Average Turnaround time:" << t_avg << "\n";
}
