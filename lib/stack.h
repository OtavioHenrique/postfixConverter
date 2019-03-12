#include <stdio.h>
#include <stdlib.h>

typedef char Item;

typedef struct stack {
    int maxItems;
    int head;
    Item *items;
} *Stack;

Stack createStack(int maxItems) {
    Stack newStack = malloc(sizeof(Stack));
    newStack->maxItems = maxItems;
    newStack->head = -1;
    newStack->items = malloc(sizeof(Item) * maxItems);

    return newStack;
}

int isEmpty(Stack stack) {
    if(stack->head == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(Stack stack) {
    if(stack->head == stack->maxItems-1) {
        return 1;
    } else {
        return 0;
    }
}

void addItem(Item newItem, Stack stack) {
    if(isFull(stack) == 0) {
        stack->head++;

        stack->items[stack->head] = newItem;
    } else {
        puts("Stack is full!");
    }
}

void destroyStack(Stack *stack) {
    free((*stack)->items);
    free(*stack);
    *stack = NULL;
}

Item stackHead(Stack stack) {
    if(isEmpty(stack) == 1)
        puts("Stack is empty");

    return stack->items[stack->head];
}

Item removeItem(Stack stack) {
    if(isEmpty(stack) == 1)
        puts("Stack is empty!");

    Item removedItem = stack->items[stack->head];
    stack->head--;

    return removedItem;
}
