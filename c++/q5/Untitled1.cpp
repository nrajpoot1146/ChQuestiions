#include <stdio.h>

#include <pthread.h>

void *increment_function1(void *);

void *increment_function2(void *);

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int counter1 = 0;
int counter2 = 0;

int main()

{

    int rc1, rc2;

    pthread_t thread1, thread2;

    if ((rc1 = pthread_create(&thread1, NULL, &increment_function1, NULL)))
    {

        printf("Thread creation failed: %d\n", rc1);
    }

    if ((rc2 = pthread_create(&thread2, NULL, &increment_function2, NULL)))
    {

        printf("Thread creation failed: %d\n", rc2);
    }

    pthread_join(thread1, NULL);

    pthread_join(thread2, NULL);

    printf("Counter value: %d\n", counter1);

    printf("Counter2 value: %d\n", counter2);

    return 0;
}

void *increment_function1(void *arg)

{

    int i;

    for (i = 0; i < 40000; i++)
    {

        pthread_mutex_lock(&mutex1);

        counter1 = counter1 + 1;

        counter2 = counter2 + 1;

        pthread_mutex_unlock(&mutex1);
    }

    return NULL;
}

void *increment_function2(void *arg)

{

    int i;

    for (i = 0; i < 50000; i++)
    {

        pthread_mutex_lock(&mutex1);

        counter1 = counter1 + 1;

        pthread_mutex_unlock(&mutex1);

        counter2 = counter2 + 1;
    }

    return NULL;
}
