#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "int_stress.h"
#include "list.h"

int main(int argc, char **argv) {
    printf("Hello world\n");
    
    list_t *testList = newList();

    prependNode(1, testList);
    appendNode(2, testList);
    appendNode(3, testList);
    prependNode(0, testList);

    int headTest = getHeadNode(testList);
    int tailTest = getTailNode(testList);
    printf("Head is %d, tail is %d.\n", headTest, tailTest);

    deleteList(&testList);


    pthread_t thread1, thread2, thread3, thread4;

    // Starting threads with sleeps in between to
    // see incremental "step-up" in CPU Util
    pthread_create(&thread1, NULL, intrate_alu, NULL);
    sleep(5);
    pthread_create(&thread2, NULL, intrate_alu, NULL);
    sleep(5);
    pthread_create(&thread3, NULL, intrate_alu, NULL);
    sleep(5);
    pthread_create(&thread4, NULL, intrate_alu, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    return 0;
}
