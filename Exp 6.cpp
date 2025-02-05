#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int burst_time;
    int priority;
};

void sortProcesses(struct Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].priority > proc[j + 1].priority) {
                struct Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
}

void preemptivePriorityScheduling(struct Process proc[], int n) {
    sortProcesses(proc, n);
    printf("Process ID\tBurst Time\tPriority\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burst_time, proc[i].priority);
    }
}

int main() {
    struct Process proc[] = {{1, 10, 2}, {2, 5, 1}, {3, 8, 3}};
    int n = sizeof(proc) / sizeof(proc[0]);
    preemptivePriorityScheduling(proc, n);
    return 0;
}
