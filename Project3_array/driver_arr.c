// Project 3 Equation Checker
// Created by fahim on 6/29/2023.
// UT EID: fmi89
// Vivek Telang, Hamza Masood, Saher Elsayed

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack312_arr.h"

#define MAX_EXPRESSION_LENGTH 80

// Function to check if a character is a valid opening delimiter
bool isOpeningDelimiter(char ch) {
    return ch == '(' || ch == '[' || ch == '<';
}

// Function to check if a character is a valid closing delimiter
bool isClosingDelimiter(char ch) {
    return ch == ')' || ch == ']' || ch == '>';
}

// Function to check if two delimiters are matching pairs
bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '<' && closing == '>');
}

// Function to check the validity of an expression
void checkExpressionValidity(const char *expression) {
    Stack312 stack;
    makeStack(&stack);

    int length = strlen(expression);
    for (int i = 0; i < length; i++) {
        char current = expression[i];

        if (isOpeningDelimiter(current)) {
            push(current, &stack);
        } else if (isClosingDelimiter(current)) {
            if (isEmpty(stack)) {
                printf("Invalid expression. Extra closing delimiter: %c\n", current);
                return;
            }

            char top = pop(&stack);
            if (!isMatchingPair(top, current)) {
                printf("Invalid expression. Mismatched pair: %c %c\n", top, current);
                return;
            }
        }
    }

    if (!isEmpty(stack)) {
        printf("Invalid expression. Missing closing delimiter.\n");
    } else {
        printf("Valid expression.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open input file: %s\n", filename);
        return 1;
    }

    char expression[MAX_EXPRESSION_LENGTH];
    while (fgets(expression, sizeof(expression), file)) {
        // Remove newline character
        expression[strcspn(expression, "\n")] = '\0';

        checkExpressionValidity(expression);
    }

    fclose(file);
    return 0;
}
