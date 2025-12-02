#pragma once
#include <stdio.h>
#include <stdlib.h>


typedef struct list list_t;

// list constructor
list_t* newList();

// list destructor
void deleteList(list_t **l);

// Prepend a node to list
void prependNode(int data, list_t *l);

// Append a node to list
void appendNode(int data, list_t *l);

