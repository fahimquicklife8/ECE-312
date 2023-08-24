/* mathStuff_xxxxxx.c

Programmer: 
EE312  <date>

Finish comments here
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//**********  Function Prototypes  ******************

#include <stdio.h>
#include <stdbool.h>

bool isPrimeHelper(int number, int divisor);

bool isPrime(int number) {
    if (number <= 0) {
        printf("Invalid input, please enter a positive integer.\n");
        return false;
    }
    if (number == 1) {
        return false;
    }

    return isPrimeHelper(number, 2);
}

bool isPrimeHelper(int number, int divisor) {
    if (divisor * divisor > number) {
        return true;
    }
    if (number % divisor == 0) {
        return false;
    }
    return isPrimeHelper(number, divisor + 1);
}

void printPrimesHelper(int n, int current) {
    if (current <= n) {
        if (isPrime(current)) {
            printf("%d ", current);
        }
        printPrimesHelper(n, current + 1);
    }
}

void printPrimes(int n) {
    if (n < 0) {
        printf("Invalid input, please enter a positive integer.\n");
        return;
    }
    if (n < 2) {
        return;
    }
    printPrimesHelper(n, 2);
}

int findFibo(int n) {
    if (n < 0) {
        printf("Invalid input, please enter a non-negative integer.\n");
        return -1; // Or any other appropriate action for negative input
    }
    if (n <= 1) {
        return n;
    }
    return findFibo(n - 1) + findFibo(n - 2);
}

void findFactorsHelper(int number, int divisor) {
    if (divisor > number) {
        return;
    }
    if (number % divisor == 0) {
        printf("%d", divisor);
        if (divisor != number) {
            printf("*");
        }
        findFactorsHelper(number / divisor, divisor);
    } else {
        findFactorsHelper(number, divisor + 1);
    }
}

void findFactors(int number) {
    if (number < 2) {
        printf("No factors for %d\n", number);
        return;
    }
    printf("%d=", number);
    findFactorsHelper(number, 2);
    printf("\n");
}

int main() {
    int testNum;

    // Test for the isPrime function
    printf("Enter a test number: ");
    scanf("%d", &testNum);

    if (isPrime(testNum))
        printf("%d is prime\n", testNum);
    else
        printf("%d is not prime.\n", testNum);

    // Test for printing primes
    printf("Enter n to print the prime numbers between 1 and n: ");
    scanf("%d", &testNum);

    if (testNum < 0) {
        printf("Invalid input, please enter a positive integer.\n");
    } else {
        printPrimes(testNum);
    }
    printf("\n");

    // Test for Fibonacci number finder
    printf("Which Fibonacci number? ");
    scanf("%d", &testNum);

    if (testNum < 0) {
        printf("Invalid input, please enter a non-negative integer.\n");
    } else {
        printf("The %d Fibonacci number is: %d\n", testNum, findFibo(testNum));
    }
    printf("\n");

    // Test for prime factors
    printf("Factor what number? ");
    scanf("%d", &testNum);

    findFactors(testNum);

    return 0;
}
