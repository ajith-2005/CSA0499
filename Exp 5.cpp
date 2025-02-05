#include <stdio.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int priority;
} Process;

void schedule(Process processes[], int count) {
    int highestPriorityIndex = 0;

    for (int i = 1; i < count; i++) {
        if (processes[i].priority > processes[highestPriorityIndex].priority) {
            highestPriorityIndex = i;
        }
    }

    printf("Executing Process ID: %d with Priority: %d\n", 
           processes[highestPriorityIndex].id, 
           processes[highestPriorityIndex].priority);
}

int main() {
    Process processes[MAX_PROCESSES] = {
        {1, 2},
        {2, 5},
        {3, 1},
        {4, 4}
    };

    schedule(processes, 4);
    return 0;
}
