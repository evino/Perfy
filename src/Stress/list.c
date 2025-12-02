#include "list.h"

typedef struct node node_t;
struct node {
    int data;
    node_t *prev;
    node_t *next;
};
    

struct list {
    int size;
    node_t *head;
    node_t *tail;
};

// private node constructor
node_t *newNode(int data) {
    node_t *n = malloc(sizeof(node_t));
    n->data = data;
    n->prev = NULL;
    n->next = NULL;

    return n;
}

// private node destructor
void deleteNode(node_t **n) {
    free(*n);
    *n = NULL;
    n = NULL;

    return;
}

// list constructor
list_t* newList() {
    list_t *l = malloc(sizeof(list_t));
    l->size = 0;
    l->head = NULL;
    l->tail = NULL;

    return l;
}


