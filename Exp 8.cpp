#include <stdio.h>

#define MAX 10

struct Process {
    int id;
    int burst_time;
    int remaining_time;
};

void roundRobin(struct Process processes[], int n, int quantum) {
    int time = 0;
    int done = 0;

    while (done < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time > quantum) {
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    done++;
                    printf("Process %d completed at time %d\n", processes[i].id, time);
                }
            }
        }
    }
}

int main() {
    struct Process processes[MAX] = {
        {1, 10, 10},
        {2, 5, 5},
        {3, 8, 8}
    };
    int n = 3;
    int quantum = 3;

    roundRobin(processes, n, quantum);
    return 0;
}
