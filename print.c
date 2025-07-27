#include <stdio.h>
#include <pthread.h>

#define MAX 10

int counter = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;
int turn = 0; // 0 = even's turn, 1 = odd's turn

void* print_even(void* arg) {
    while (counter <= MAX) {
        pthread_mutex_lock(&mutex);

        while (turn != 0 && counter <= MAX)
            pthread_cond_wait(&cond, &mutex);

        if (counter % 2 == 0 && counter <= MAX) {
            printf("%d\n", counter);
            counter++;
            turn = 1; // now odd thread's turn
            pthread_cond_signal(&cond);
        }

        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* print_odd(void* arg) {
    while (counter <= MAX) {
        pthread_mutex_lock(&mutex);

        while (turn != 1 && counter <= MAX)
            pthread_cond_wait(&cond, &mutex);

        if (counter % 2 == 1 && counter <= MAX) {
            printf("%d\n", counter);
            counter++;
            turn = 0; // now even thread's turn
            pthread_cond_signal(&cond);
        }

        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t t_even, t_odd;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&t_even, NULL, print_even, NULL);
    pthread_create(&t_odd, NULL, print_odd, NULL);

    pthread_join(t_even, NULL);
    pthread_join(t_odd, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
