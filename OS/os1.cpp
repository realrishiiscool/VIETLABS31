#include <stdio.h>
void roundRobin(int processes[], int n, int bt[], int quantum)
{
    int wt[n], tat[n], rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    int t = 0; // Current time
    while (1)
    {
        int done = 1;
        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = 0;
                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    // Print waiting and turnaround times
    for (int i = 0; i < n; i++)
        printf("Process %d: WT = %d, TAT = %d\n", processes[i], wt[i], tat[i]);
}

int main()
{
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {10, 5, 8};
    int quantum = 2;
    roundRobin(processes, n, burst_time, quantum);
    return 0;
}
