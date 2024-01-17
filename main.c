
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>  // For atoi function

pthread_mutex_t dataMutex = PTHREAD_MUTEX_INITIALIZER;

void processData(int data) { // Simulate data processing logic// Synchronize access to shared data
    pthread_mutex_lock(&dataMutex);// Simulate storing processed data
    printf("Processed data: %d\n", data);
    pthread_mutex_unlock(&dataMutex);
}
void* threadFunction(void* arg) {
    int data = *((int*)arg);
    processData(data);
    return NULL;
}
int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <data1> <data2>\n", argv[0]);
        return 1;
    }// Convert command-line arguments to integers
    int data1 = atoi(argv[1]);
    int data2 = atoi(argv[2]);
    pthread_t thread1, thread2;// Create threads for data processing
    pthread_create(&thread1, NULL, threadFunction, &data1);
    pthread_create(&thread2, NULL, threadFunction, &data2);// Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}

