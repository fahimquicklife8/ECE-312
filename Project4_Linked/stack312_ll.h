// Project 3 Linked List
// Created by fahim on 6/29/2023.
// UT EID: fmi89
// Vivek Telang, Hamza Masood, Saher Elsayed


#ifndef PROJECT3_LL_STACK312_LL_H
#define PROJECT3_LL_STACK312_LL_H

#endif //PROJECT3_LL_STACK312_LL_H


#include <stdio.h>
#include <stdbool.h>

typedef struct Pixel {
    int row;
    int col;
    char color;
} Pixel;

typedef Pixel StackEntry;

typedef struct StackNode {
    StackEntry pixel;
    struct StackNode *next;
} StackNode;

typedef struct Stack312 {
    struct StackNode *top;
} Stack312;

void makeStack(Stack312 *sp);

bool isFull(Stack312 s);

bool isEmpty(Stack312 s);

void push(StackEntry e,Stack312 *sp);

StackEntry pop(Stack312 *sp);