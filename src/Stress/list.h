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

int getHeadNode(list_t *l);

int getTailNode(list_t *l);

int getCursorNode(list_t *l);

int getListSize(list_t *l);

void cursorForward(list_t *l);

void cursorBackward(list_t *l);

void cursorFront(list_t *l);

void cursorBack(list_t *l);

void traverseList(list_t *l);

