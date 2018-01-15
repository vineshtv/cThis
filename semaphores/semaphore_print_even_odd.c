/*
 *  A program which uses two semaphores to synchronize between two threads.
 *  Thread 1 prints even numbers from 0 to 10
 *  Thread 2 prints odd numbers from 1 to 9
 */
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>

sem_t sem1;
sem_t sem2;

void *evenNumbers()
{
    static int countEven = 0;
    while(countEven <= 10)
    {
        sem_wait(&sem1);
        printf("%d\n", countEven);
        countEven += 2;
        sem_post(&sem2);
    }
}

void *oddNumbers()
{
    static int countOdd = 1;
    while(countOdd <= 10)
    {
        sem_wait(&sem2);
        printf("%d\n", countOdd);
        countOdd += 2;
        sem_post(&sem1);
    } 
}

int main()
{
    pthread_t thread1, thread2;

    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 0);

    pthread_create(&thread1, NULL, evenNumbers, NULL);
    pthread_create(&thread2, NULL, oddNumbers, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
