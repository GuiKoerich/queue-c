#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "adt.h"

typedef struct Queue {
    struct Item *first;
    int length;
} Queue;

struct Queue* allocMemory();
void freeMemory();
struct Item* allocMemoryItem();
void freeMemoryItem();
int fullMemory(struct Item *item);

void newQueue();
int isEmpty();
int length();
void queue(int value);
void dequeue(int *value);
int first(int *value);
void showQueue();
void emptyQueue();

#endif