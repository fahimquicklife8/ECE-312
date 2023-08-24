// life.h
// -- ECE 312 Project 2

/* Student information for project:
 *
 * Replace <Fahim> with your name.
 *
 * On my honor, <Fahim>, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Fahim Imtiaz
 * email address: fahim7@utexas.edu
 * UTEID: fmi89
 * Section 5digit ID: 75590
 *
 *///
// Created by Priebe on 9/5/2018.
//

#ifndef UNTITLED1_LIFE_H
#define UNTITLED1_LIFE_H
#endif //UNTITLED1_LIFE_H

int countNeighbors(char* grid[], int row, int col,int numRows, int numCols); // , int i, int j

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols);

void showWorld(char *grid[], int numRows, int numCols);

void iterateGeneration(char *grid[], int numRows, int numCols);
