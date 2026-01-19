#pragma once
#include "list.h"
#include <stdlib.h>

// Create a list of defined size. Each node holds random interger between 0 and 99
list_t *listInit(size_t size);

void PointerChase(list_t *l);

