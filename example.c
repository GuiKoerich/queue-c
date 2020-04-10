#include <stdlib.h>
#include <stdio.h>
#include "queue.c"

void fibonacci(int position) {
    newQueue();

    int first = 1;
    int second = 1;
    int next;

    queue(first);
    queue(second);

    for(int count = 0; count < position; count++) {
        next = first + second;
        queue(next);

        first = second;
        second = next;
    }
}

void main() {
    fibonacci(8);
    showQueue();
    emptyQueue();
}