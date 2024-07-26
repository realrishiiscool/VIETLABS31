#include <stdio.h>

void priorityScheduling(int processes[], int n, int bt[], int priority[]) {
    int wt[n], tat[n], temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = bt[i-1] + wt[i-1];

    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
    
    // Print waiting and turnaround times
    for (int i = 0; i < n; i++)
        printf("Process %d: WT = %d, TAT = %d\n", processes[i], wt[i], tat[i]);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {10, 5, 8};
    int priority[] = {2, 1, 3};
    priorityScheduling(processes, n, burst_time, priority);
    return 0;
}

