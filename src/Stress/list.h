#pragma once
#include <stdio.h>
#include <stdlib.h>


typedef struct list list_t;

// list constructor
list_t* newList();

// list destructor
void deleteList(list_t **l);

