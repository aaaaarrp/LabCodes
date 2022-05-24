
// Banker's Algorithm
#include <iostream>
using namespace std;

int main()
{
    // P0, P1, P2, P3, P4 are the Process names here

    int n, m, i, j, k;                  // k = instances
    n = 5;                              // Number of processes
    m = 3;                              // Number of resources
    int allocation[5][3] = {{0, 1, 0},  // P0 // Allocation Matrix
                            {2, 0, 0},  // P1
                            {3, 0, 2},  // P2
                            {2, 1, 1},  // P3
                            {0, 0, 2}}; // P4

    int max_demand[5][3] = {{7, 5, 3},  // P0 // MAX_DEMAND Matrix
                            {3, 2, 2},  // P1
                            {9, 0, 2},  // P2
                            {2, 2, 2},  // P3
                            {4, 3, 3}}; // P4

    int available__resources[3] = {3, 3, 2}; // Available Resources

    int finish[n], sequence[n], index = 0;   // index to maintain order in the sequence
    for (k = 0; k < n; k++)
    {
        finish[k] = 0;      // Initially Finish[i] = false; for i=1, 2, 3, 4….n (marking all the process as false)
    }                       // If one process finishes then we can mark them true later
    
    int remaining_need[n][m];   // Remaining Need = Max_Demand - Allocation
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            remaining_need[i][j] = max_demand[i][j] - allocation[i][j];
    }

    int y = 0;  // for resources 
    for (k = 0; k < 5; k++)     // Going through all the process
    {
        for (i = 0; i < n; i++) // Checks for all the instances
        {
            if (finish[i] == 0) // any instance with false sign (which is not in sequence)
            {

                int flag = 0;   //initially flag kept = 0

                // Not fulfilling condition
                for (j = 0; j < m; j++) // for the 3 resources
                {
                    if (remaining_need[i][j] > available__resources[j])
                    {               // process is false & remaining need > available resources
                        flag = 1;   // process must wait & flag changed to 1
                        break;
                    }
                }

                // Fulfilling condition
                if (flag == 0)
                {                                                       // one process finished successfully as flag remained 0
                    sequence[index++] = i;                              // increment the index and we'll put the process's index in sequence
                    for (y = 0; y < m; y++)
                        available__resources[y] += allocation[i][y];    // we'll add it's allocation to available resources
                    finish[i] = 1;                                      // then mark the process as true (won't be checked again)
                }
            }
        }
    }

    int flag = 1;  // Used to check whether a process true or not (initially kept 0)

    // To check if sequence is safe or not
    for (int i = 0; i < n; i++)
    {
        if (finish[i] == 0) // if we find any process false(didn't occur)  -> mark flag 0 and break -> system is not safe
        {
            flag = 0;
            cout << "The given sequence is not safe";
            break;
        }
    }

    if (flag == 1)  // if flag is 1(which means there was no deadlock), system is safe -> print sequence
    {
        cout << "\nFollowing is the SAFE Sequence" << endl;
        for (i = 0; i < n - 1; i++)
            cout << " P" << sequence[i] << " ->";
        cout << " P" << sequence[n - 1] << endl;    // for the last remaining index
    }

    return (0);
}
