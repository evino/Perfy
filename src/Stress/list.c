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
    node_t *cursor;
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
list_t *newList() {
    list_t *l = malloc(sizeof(list_t));
    l->size = 0;
    l->head = NULL;
    l->tail = NULL;
    l->cursor = NULL;
    return l;
}

void cursorForward(list_t *l) {
    if (l->size == 0) {
        fprintf(stderr, "Empty list\n");
        return;
    }

    if (l->cursor->next == NULL) {
        return;
    }

    l->cursor = l->cursor->next;

    return;
}

void cursorBackward(list_t *l) {
    if (l->size == 0) {
        fprintf(stderr, "Empty list\n");
        return;
    }

    if (l->cursor->prev == NULL) {
        return;
    }

    l->cursor = l->cursor->prev;
    return;
}

int getListSize(list_t *l) {
    return l->size;
}

void prependNode(int data, list_t *l) {
    node_t *n = newNode(data);
    if (l->size == 0) {
        l->head = n;
        l->tail = n;
        l->size = 1;
        l->cursor = n;
        return;
    }

    l->head->prev = n;
    n->next = l->head;
    l->head = n;
    l->size += 1;

    return;
}

void appendNode(int data, list_t *l) {
    node_t *n = newNode(data);
    if (l->size == 0) {
        prependNode(data, l);
        return;
    }

    l->tail->next = n;
    n->prev = l->tail;
    l->tail = n;
    l->size += 1;

    return;
}

int getHeadNode(list_t *l) {
    if (l->head == NULL) {
        return -1;
    }

    return l->head->data;
}

int getTailNode(list_t *l) {
    if (l->tail == NULL) {
        return -1;
    }

    return l->tail->data;
}

