#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

// CodeCamp.c -- EE 312 Project 1

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
 */
/* Determine the hamming distance between two int arrays.
   pre: aList != null, bList != null, aList.length == bList.length == len
   post: return hamming distance between the two arrays of ints.
   Neither parameter should be altered by this function.
*/

int hammingDistance(int aList[], int bList[], int len) {
    int j, count = 0;
    for( j = 0; j < len; j++) {
        count += (aList[j] != bList[j]) ? 1 : 0;
    }
    return count;
}

bool lastDigit(int x, int y) {
    int lastDigit_x = abs(x % 10);
    int lastDigit_y = abs(y % 10);
    return lastDigit_x == lastDigit_y;
}

int sum3or5Multiples() {
    int k, total = 0;
    for( k = 3; k < 1000; k++) {
        if(k % 3 == 0 || k % 5 == 0) {
            total += k;
        }
    }
    return total;
}

int reverseInt(int x) {
    long reversedNum = 0;
    while(x != 0) {
        reversedNum = reversedNum * 10 + x % 10;
        x /= 10;
    }
    if(reversedNum < INT_MIN || reversedNum > INT_MAX) {
        return 0;
    }
    return (int)reversedNum;
}
