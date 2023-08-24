// Project 3 Equation checker
// Created by fahim on 6/29/2023.
// UT EID: fmi89
// Vivek Telang, Hamza Masood, Saher Elsayed
//
// Created by fahim on 6/29/2023.
//


#include <stdio.h>
#include "stack312_arr.h"

void makeStack(Stack312 *sp) {
    sp->top = -1;
}

bool isFull(Stack312 s) {
    return s.top == MAX_ELEMENTS - 1;
}

bool isEmpty(Stack312 s) {
    return s.top == -1;
}

void push(StackEntry e, Stack312 *sp) {
    if (!isFull(*sp)) {
        sp->elements[++sp->top] = e;
    }
}

StackEntry pop(Stack312 *sp) {
    if (!isEmpty(*sp)) {
        return sp->elements[sp->top--];
    } else {
        // Handle stack underflow error
        printf("Stack is empty. Cannot perform pop operation.\n");
        return '\0';
    }
}
