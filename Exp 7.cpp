#include <stdio.h>

struct Process {
    int id;
    int burst_time;
    int waiting_time;
};

void findWaitingTime(struct Process proc[], int n) {
    proc[0].waiting_time = 0; 
    for (int i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i - 1].waiting_time + proc[i - 1].burst_time;
    }
}

void findTurnAroundTime(struct Process proc[], int n, int turnaround_time[]) {
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = proc[i].burst_time + proc[i].waiting_time;
    }
}

void sjfScheduling(struct Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].burst_time > proc[j + 1].burst_time) {
                struct Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }

    int turnaround_time[n];
    findWaitingTime(proc, n);
    findTurnAroundTime(proc, n, turnaround_time);

    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burst_time, proc[i].waiting_time, turnaround_time[i]);
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process proc[n];

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1; // Assign process ID
        printf("Enter burst time for process %d: ", proc[i].id);
        scanf("%d", &proc[i].burst_time);
    }

    sjfScheduling(proc, n);
    return 0;
}
