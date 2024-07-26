#include <stdio.h>

void sjf(int processes[], int n, int bt[]) {
    int wt[n], tat[n], temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
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
    sjf(processes, n, burst_time);
    return 0;
}
	
