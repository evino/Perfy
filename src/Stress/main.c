#include <stdio.h>
#include <pthread.h>
#include "int_stress.h"

int main(int argc, char **argv) {
    printf("Hello world\n");

    pthread_t thread1, thread2, thread3, thread4;

    pthread_create(&thread1, NULL, intrate_alu, NULL);

    pthread_join(thread1, NULL);
    return 0;
}
