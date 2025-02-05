#include <stdio.h>

struct Process {
    int id;
    int burstTime;
};

void findWaitingTime(struct Process proc[], int n, int waitTime[]) {
    waitTime[0] = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        waitTime[i] = proc[i - 1].burstTime + waitTime[i - 1];
    }
}

void findTurnAroundTime(struct Process proc[], int n, int waitTime[], int turnAroundTime[]) {
    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = proc[i].burstTime + waitTime[i];
    }
}

void findavgTime(struct Process proc[], int n) {
    int waitTime[n], turnAroundTime[n];
    findWaitingTime(proc, n, waitTime);
    findTurnAroundTime(proc, n, waitTime, turnAroundTime);

    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burstTime, waitTime[i], turnAroundTime[i]);
    }
}

int main() {
    struct Process proc[] = {{1, 5}, {2, 3}, {3, 8}};
    int n = sizeof(proc) / sizeof(proc[0]);
    findavgTime(proc, n);
    return 0;
}
