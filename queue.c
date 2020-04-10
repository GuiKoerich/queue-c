#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

struct Queue *_queue;

struct Queue* allocMemory() {
    return (Queue*)malloc(sizeof(Queue));
}

void freeMemory() {
    _queue->first = NULL;
    free(_queue);
}

struct Item* allocMemoryItem() {
    return (Item*)malloc(sizeof(Item));
}

void freeMemoryItem(struct Item *item) {
    item->next = NULL;
    free(item);
}

int fullMemory(struct Item *item) {
    return item == NULL;
}

void newQueue() {
    _queue = allocMemory();
    _queue->first = NULL;
    _queue->length = 0;
}

int isEmpty() {
    return _queue->first == NULL;
}

int length() {
    return _queue->length;
}

int first(int *value) {
    if(!isEmpty()) {
        *value = _queue->first->value;

        return 1;
    }

    return 0;
}

void queue(int value) {
    Item *item = allocMemoryItem();

    if(!fullMemory(item)) {
        item->value = value;
        item->next = NULL;

        if(isEmpty()) {
            _queue->first = item;

        } else {
            Item *temp = _queue->first;

            while(temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = item;
        }

        _queue->length++;
    }
}

void dequeue(int *value) {
    if(!isEmpty()) {
        Item *temp = _queue->first;

        *value = temp->value;

        if(temp->next != NULL) {
            _queue->first = temp->next;

        } else {
            _queue->first = NULL;

        }

        _queue->length--;

        freeMemoryItem(temp);
    }
}

void showQueue() {
    printf("\n====== INITIAL ======\n");

    if(isEmpty()) {
        printf("--- QUEUE IS EMPTY ---");

    } else {
        int queue_length = length();

        Item *temp = _queue->first;

        int position = 1;

        for(int cont = 0; cont < queue_length; cont++) {
            printf("- [%d] -- %d -- \n", position, temp->value);

            if(temp->next != NULL) {
                temp = temp->next;
            }

            position++;
        }
    }

    printf("====== FINAL ======\n");
}

void emptyQueue() {
    if(isEmpty()) {
        printf("The queue already empty");

    } else {
        int eliminated = first(&eliminated);
        int ord = 1;

        while(!isEmpty()) {
            dequeue(&eliminated);
            printf("-- %dº Eliminated value: %d\n", ord, eliminated);
            ord++;
        }

        printf("The queue is empty!");
    }
}