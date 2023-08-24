// Project 3 Linked List
// Created by fahim on 6/29/2023.
// UT EID: fmi89
// Vivek Telang, Hamza Masood, Saher Elsayed


#include <stdio.h>
#include "stack312_ll.h"

char picture[25][25];
int numRows = 0;
int numCols = 0;

void readPicture(char* fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Cannot open file.\n");
        return;
    }

    char c;
    int r = 0, column = 0;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            r++;
            column = 0;
        } else {
            picture[r][column] = c;
            column++;
            if (column > numCols)
                numCols = column;
        }
    }

    numRows = r+1; // ensure the last row is included
    fclose(file);
}

void displayPicture() {
    for (int j = 0; j < numRows; j++)
    {
        for (int k = 0; k < numCols; k++)
        {
            printf("%c", picture[j][k]);
        }
        printf("\n");
    }
}

void floodFill(int row, int column, char nColor) {
    Stack312 stack;
    makeStack(&stack);

    char oColor = picture[row][column];
    Pixel srtPixel = {row, column, nColor};
    push(srtPixel, &stack);

    while (!isEmpty(stack)) {
        Pixel crntPixel = pop(&stack);
        picture[crntPixel.row][crntPixel.col] = nColor;

        // For 8 directions
        int dr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
        int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};

        for (int j = 0; j < 8; j++) {
            int newRows = crntPixel.row + dr[j];
            int newColumns = crntPixel.col + dc[j];

            if (newRows >= 0 && newRows < numRows && newColumns >= 0 && newColumns < numCols &&
                picture[newRows][newColumns] == oColor) {
                Pixel newPixel = {newRows, newColumns, nColor};
                push(newPixel, &stack);
            }
        }
    }

    displayPicture();
}



int main(int argc, char** argv) {
    readPicture(argv[1]);
    displayPicture();

    int row, column;
    char color;

    while (1) {
        printf("Enter a row: ");
        scanf("%d", &row);
        if (row == -1) break;
        printf("Enter a column: ");
        scanf("%d", &column);
        if (column == -1) break;
        printf("Enter a color: ");
        scanf(" %c", &color);
        floodFill(row, column, color);
    }

    return 0;
}