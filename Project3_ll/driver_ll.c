// Project 3 Linked List
// Created by fahim on 6/29/2023.
// UT EID: fmi89
// Vivek Telang, Hamza Masood, Saher Elsayed

#include "stack312_ll.h"
#include <stdlib.h>

void makeStack(Stack312 *sp) {
    sp->top = NULL;
}

bool isFull(Stack312 s) {
    return false; // In linked list implementation, stack is never full until memory exhaustion.
}

bool isEmpty(Stack312 s) {
    return (s.top == NULL);
}

void push(StackEntry e, Stack312 *sp) {
    StackNode *nNode = (StackNode*)malloc(sizeof(StackNode));
    if (nNode != NULL) {
        nNode->pixel = e;
        nNode->next = sp->top;
        sp->top = nNode;
    }
}

StackEntry pop(Stack312 *sp) {
    if (!isEmpty(*sp)) {
        StackNode *temp = sp->top;
        StackEntry poppedItem = temp->pixel;
        sp->top = sp->top->next;
        free(temp);
        return poppedItem;
    } else {
        StackEntry d = {-1, -1, ' '};  // Return a dummy value if stack is empty
        return d;
    }
}
