#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "life.h"

// Helper function to count the number of neighboring cells that are alive
int countNeighbors(char *grid[], int row, int col, int numRows, int numCols) {
    int count = 0;

    // Check each neighboring cell
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int neighborRow = row + i;
            int neighborCol = col + j;

            // Skip the current cell
            if (i == 0 && j == 0) {
                continue;
            }

            // Check if the neighboring cell is within the grid bounds and alive
            if (neighborRow >= 0 && neighborRow < numRows && neighborCol >= 0 && neighborCol < numCols) {
                if (grid[neighborRow][neighborCol] == '1') {
                    count++;
                }
            }
        }
    }

    return count;
}

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols) {
    FILE *file = fopen(fname, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the file line by line
    int row = 0;
    char line[80]; // Assuming a maximum line length of 80 characters

    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove newline character at the end of the line
        line[strcspn(line, "\n")] = '\0';

        // Allocate memory for the row and copy the line into the grid
        grid[row] = malloc(strlen(line) + 1);
        strcpy(grid[row], line);

        row++;
    }

    *numRows = row;
    *numCols = strlen(grid[0]);

    fclose(file);
}

void showWorld(char *grid[], int numRows, int numCols) {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            if (grid[row][col] == '1') {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void iterateGeneration(char *grid[], int numRows, int numCols) {
    // Dynamically allocate memory for the newGrid array
    char **newGrid = malloc(numRows * sizeof(char *));
    for (int row = 0; row < numRows; row++) {
        newGrid[row] = malloc((numCols + 1) * sizeof(char));
    }

    // Iterate over each cell in the grid
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            int aliveNeighbors = countNeighbors(grid, row, col, numRows, numCols);

            // Apply the rules of the Game of Life
            if (grid[row][col] == '1') {
                if (aliveNeighbors == 2 || aliveNeighbors == 3) {
                    newGrid[row][col] = '1'; // Cell survives
                } else {
                    newGrid[row][col] = '0'; // Cell dies
                }
            } else {
                if (aliveNeighbors == 3) {
                    newGrid[row][col] = '1'; // New cell is born
                } else {
                    newGrid[row][col] = '0'; // Cell remains dead
                }
            }
        }
        newGrid[row][numCols] = '\0'; // Null-terminate the row
    }

    // Update the original grid with the new generation
    for (int row = 0; row < numRows; row++) {
        strcpy(grid[row], newGrid[row]);
        free(newGrid[row]); // Free the memory for each row of newGrid
    }
    free(newGrid); // Free the memory for newGrid itself
}
