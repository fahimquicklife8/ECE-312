#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "life.h"

#define MAX_ROWS 80 //we want the world to fit on one screen

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: %s <input_file> <num_generations>\n", argv[0]);
        exit(0);
    }

    const char* fName = argv[1];
    const int numGenerations = atoi(argv[2]);

    //array of strings that will hold the grid
    char *world[MAX_ROWS];

    int numRows;
    int numCols;

    populateWorld(fName, world, &numRows, &numCols);

    showWorld(world, numRows, numCols);

    for (int iteration = 0; iteration < numGenerations; iteration++) {

        // Add a safety check to prevent accessing memory beyond allocated limit
        if (iteration < MAX_ROWS) {
            iterateGeneration(world, numRows, numCols);
            showWorld(world, numRows, numCols);
        }
    }

    return 0;
}
