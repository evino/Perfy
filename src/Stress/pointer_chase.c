#include "pointer_chase.h"

// Create a list of defined size. Each node holds random interger between 0 and 99
list_t *listInit(size_t size) {
    list_t *l = newList();

    for (size_t i = 0; i < size; i += 1) {
        int random_int = random();
        appendNode(random_int, l);
    }

    return l;
}

