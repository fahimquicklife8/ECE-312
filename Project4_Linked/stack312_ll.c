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

void floodFill(int row, int col, char oColor, char nColor) {
    if (row < 0 || row >= numRows || col < 0 || col >= numCols || picture[row][col] != oColor || picture[row][col] == nColor) {
        return;
    }
    if (row < 0 || row >= numRows || col < 0 || col >= numCols)
        return;

    if (picture[row][col] != oColor)
        return;

    picture[row][col] = nColor;

    floodFill(row-1, col, oColor, nColor);
    floodFill(row+1, col, oColor, nColor);
    floodFill(row, col-1, oColor, nColor);
    floodFill(row, col+1, oColor, nColor);
    floodFill(row-1, col-1, oColor, nColor);
    floodFill(row+1, col+1, oColor, nColor);
    floodFill(row-1, col+1, oColor, nColor);
    floodFill(row+1, col-1, oColor, nColor);
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

        char oColor = picture[row][column];
        floodFill(row, column, oColor, color);
        displayPicture();
    }


    return 0;
}