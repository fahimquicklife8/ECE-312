// Project 3 Equation checker
// Created by fahim on 6/29/2023.
// UT EID: fmi89
// Vivek Telang, Hamza Masood, Saher Elsayed
//
// Created by fahim on 6/29/2023.
//

#ifndef PROJECT3_ARR_STACK312_ARR_H
#define PROJECT3_ARR_STACK312_ARR_H

#endif //PROJECT3_ARR_STACK312_ARR_H


#include <stdbool.h>

#define MAX_ELEMENTS 100

typedef char StackEntry;

typedef struct Stack312 {
    int top;
    StackEntry elements[MAX_ELEMENTS];
} Stack312;

void makeStack(Stack312 *sp);

bool isFull(Stack312 s);

bool isEmpty(Stack312 s);

void push(StackEntry e, Stack312 *sp);

StackEntry pop(Stack312 *sp);