# Multithreaded-C-C-Application
## Compilation and Execution Instructions:
###   1. Compile the Code:
####   Open a terminal.
####   Navigate to the directory containing the C source code file.
####   Compile the code using the following command:
####   _**gcc -pthread -o multithreaded_program multithreaded_programm.c**_
###   2. Run the Executable with Command Line Arguments:
####   After successful compilation, you can run the executable with command line arguments. For example:
####   _**./multithreaded_program 5 10**_
####   This command runs the program with the arguments 5 and 10.

## Design Explanation:
#### The program processes data concurrently using two threads. Each thread processes one piece of data. The pthread_mutex_t is used for synchronization to ensure the correct printing of processed data.

## Design Choices:
### Multithreading:
####  Two threads are created to simulate concurrent data processing. Each thread processes one piece of data.The program utilizes the pthread library for multithreading.
### Data Processing Function:
####  The processData function simulates data processing logic. In this case, it only prints the processed data, but you can extend it to perform more complex operations.
### Synchronization Mechanism:
####  A mutex (dataMutex) is used to synchronize access to the shared resource (printf). This ensures that the printf operation is atomic and avoids data corruption or interleaving output between threads.
### Error Handling:
####  The program checks whether the correct number of command-line arguments are provided. If not, it prints a usage message and exits with an error code.
### Synchronization Mechanism Used:
####  The pthread_mutex_t (mutex) is used to ensure thread-safe access to the shared resource (printf). The mutex is locked before accessing the shared resource and unlocked afterward.
### Performance Considerations:
#### The provided example is relatively simple, and performance considerations are minimal. In more complex scenarios, optimizing data processing algorithms and minimizing the time spent within critical sections can significantly impact performance.

## Additional Notes:
### Extensibility:
#### The provided code is a starting point. You can extend the processData function to include more complex data processing logic based on your application requirements.
### Optimizations:
#### Depending on the actual data processing logic, consider optimizing the algorithm for better performance.

## Source Code
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
