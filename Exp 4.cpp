#include <stdio.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int execution_time;
} Process;

void schedule(Process processes[], int n) {
    int min_index;
    while (n > 0) {
        min_index = 0;
        for (int i = 1; i < n; i++) {
            if (processes[i].execution_time < processes[min_index].execution_time) {
                min_index = i;
            }
        }
        printf("Executing Process ID: %d with Execution Time: %d\n", processes[min_index].id, processes[min_index].execution_time);
        processes[min_index] = processes[n - 1]; // Replace with the last process
        n--; // Decrease the count of processes
    }
}

int main() {
    Process processes[MAX_PROCESSES] = {
        {1, 5},
        {2, 2},
        {3, 8},
        {4, 1}
    };
    int n = 4; // Number of processes
    schedule(processes, n);
    return 0;
}
