#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_mutex_t lock;
int shared_counter = 0;

void* increment_counter(void* threadid) {
    long tid = (long)threadid;
    pthread_mutex_lock(&lock);
    
    for (int i = 0; i < 10000; i++) {
        shared_counter++;
    }
    
    printf("Thread %ld incremented counter to %d\n", tid, shared_counter);
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&lock, NULL);

    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment_counter, (void*)i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final counter value: %d\n", shared_counter);
    pthread_mutex_destroy(&lock);
    return 0;
}
