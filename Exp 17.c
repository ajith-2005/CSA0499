#include <stdio.h>
#include <stdbool.h>

#define P 5 
#define R 3 

int allocation[P][R], max[P][R], need[P][R], available[R];

bool isSafe() {
    int work[R], finish[P] = {0};
    for (int i = 0; i < R; i++) work[i] = available[i];

    while (1) {
        bool found = false;
        for (int p = 0; p < P; p++) {
            if (!finish[p]) {
                bool canAllocate = true;
                for (int r = 0; r < R; r++) {
                    if (need[p][r] > work[r]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int r = 0; r < R; r++) work[r] += allocation[p][r];
                    finish[p] = 1;
                    found = true;
                }
            }
        }
        if (!found) break;
    }

    for (int p = 0; p < P; p++) {
        if (!finish[p]) return false;
    }
    return true;
}

int main() {

    if (isSafe()) {
        printf("System is in a safe state.\n");
    } else {
        printf("System is not in a safe state.\n");
    }
    return 0;
}
