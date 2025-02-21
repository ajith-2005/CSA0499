#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_READERS 5

sem_t mutex; // Controls access to the reader count
sem_t wrt;   // Controls access to the resource
int read_count = 0;

void* reader(void* arg) {
    int id = *((int*)arg);
    while (1) {
        sem_wait(&mutex);
        read_count++;
        if (read_count == 1) {
            sem_wait(&wrt); // First reader locks the resource
        }
        sem_post(&mutex);

        // Reading section
        printf("Reader %d is reading.\n", id);
        sleep(1); // Simulate reading time

        sem_wait(&mutex);
        read_count--;
        if (read_count == 0) {
            sem_post(&wrt); // Last reader unlocks the resource
        }
        sem_post(&mutex);
        sleep(1); // Simulate time between reads
    }
}

void* writer(void* arg) {
    int id = *((int*)arg);
    while (1) {
        sem_wait(&wrt); // Writer locks the resource

        // Writing section
        printf("Writer %d is writing.\n", id);
        sleep(1); // Simulate writing time

        sem_post(&wrt); // Writer unlocks the resource
        sleep(1); // Simulate time between writes
    }
}

int main() {
    pthread_t readers[MAX_READERS], writers[MAX_READERS];
    int reader_ids[MAX_READERS], writer_ids[MAX_READERS];

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    for (int i = 0; i < MAX_READERS; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    for (int i = 0; i < MAX_READERS; i++) {
        writer_ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    for (int i = 0; i < MAX_READERS; i++) {
        pthread_join(readers[i], NULL);
        pthread_join(writers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}
