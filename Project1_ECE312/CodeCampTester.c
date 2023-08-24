#include<stdio.h>
#include<stdbool.h>


// CodeCampTester.c -- EE 312 Project 1 -- Tester class

/* Student information for assignment:
 * 
 * Name: Fahim Imtiaz
 * email address: fahim7@utexas.edu
 * UTEID: fmi89
 * Section 5 digit ID: 75590
 *  
 */

//function prototypes. These will be completed in CodeCamp.c
int hammingDistance(int aList[], int bList[], int len);
int sum3or5Multiples();
bool lastDigit(int num1, int num2);
int reverseInt(int num); 
//****************************





int main() {
    // test 1, hammingDistance
  int h1[0] ;
  int h2[0] ;
  int expected = 0;
  int actual = hammingDistance(h1, h2, 0);
  printf("Test 1 hamming distance: expected value: %d, actual value: %d\n", expected, actual);


  if(expected == actual)
     printf(" my own passed test 1, hamming distance\n\n");
  else 
     printf("**** FAILED **** test 1, hamming distance\n\n");

  //

    int arr1[9]= {1,2,3,4,5,6,8,9,10};
    int arr2[9] = {11, 12, 13, 14, 15, 16, 17, 18, 19};

    expected = 9;

     actual = hammingDistance( arr1, arr2, 9);

    printf(" Own Test 1 hamming distance: expected value: %d, actual value: %d\n", expected, actual);


    if(expected == actual)
        printf("my own passed test 1 , hamming distance\n\n");
    else
        printf("**** FAILED **** test , hamming distance\n\n");

  // test 2, hamming distance
  int h3[] = {6, 9, 12, 18, 21, 7, 7, 8, 9, 35};
  int h4[] = {17, 23, 25, 26, -36, -46, -56, -76, -33, -31};
  expected = 10;
  actual = hammingDistance(h3, h4, 10);
  printf(" My Test 2 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf(" my own test passed test 2, hamming distance\n\n");
  else 
     printf("**** FAILED **** test 2, hamming distance\n\n");

  int k1[] = {11,12,23, 14,15,16};
  int k2[] = {11, 22,23,24,15,26};
  expected = 3;
    actual = hammingDistance(k1, k2, 6);
    if(expected == actual)
        printf(" my own test 2 passed test 2, hamming distance\n\n");
    else
        printf("**** FAILED **** test 2, hamming distance\n\n");





  // test 3, hamming distance
  int h5[50000] = {0};
  int h6[50000] = {0};
  expected = 0;
  actual = hammingDistance(h5, h6, 50000);
  printf(" Own Test 3 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf(" Own passed test 3, hamming distance\n\n");
  else 
     printf("**** FAILED **** test 3, hamming distance\n\n");



  int k5[60000] = {1,2,3,4,6,7 };
  int k6[60000] = { 1,2,4,5,7,8};

  expected = 4;
    actual = hammingDistance(k5, k6, 50000);
    printf(" Own Test 3 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)
        printf(" Own passed test 3, hamming distance\n\n");
    else
        printf("**** FAILED **** test 3, hamming distance\n\n");

  // test 4, last digit
  int n1 = 0;
  int n2 = 123;
  expected = false;
  actual = lastDigit(n1, n2);
  printf("Test 4 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf(" passed own test 4, last digit\n\n");
  else 
     printf("**** FAILED **** test 4, last digit\n\n");

  int n3 = 6;
  int n4 = 666;
  expected = true;
  actual = lastDigit(n3, n4);
    printf("Test 4 last digit: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)
        printf(" passed own test 4, last digit\n\n");
    else
        printf("**** FAILED **** test 4, last digit\n\n");

  // test 5, last digit
  int c1 = -23;
  int c2 = 1534;
  expected = false;
  actual = lastDigit(c1, c2);
  printf("Test 5 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
    printf(" own test passed test 5, last digit\n\n");
  else 
     printf("**** FAILED **** test 5, last digit\n\n");


  // test 6, last digit
 int b1 = 223;
 int b2 = 3333;
  expected = true;
  actual = lastDigit(b1, b2);
  printf("Test 6 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)   
    printf("passed my own test 6, last digit\n\n");
  else 
     printf("**** FAILED **** test 6, last digit\n\n");


  // test 7, sum of multiples of 3 or 5
  expected = 233168;
  actual = sum3or5Multiples();
  printf("Test 7 sum of multiples: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 7, sum of multiples of 3 or 5\n\n");
  else 
     printf("**** FAILED **** test 7, sum of multiples of 3 or 5\n\n");



  // test 8, reverse int
  int n8 = -969;
  expected = -969;
  actual = reverseInt(n8);
  printf("Test 8 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)
     printf("my own test 8 passed, reverse int\n\n");
  else 
     printf("**** FAILED **** test 8, reverse int\n\n");
  n8 = 666;
  expected = 666;
    actual = reverseInt(n8);
    printf("Test 8 reverse int: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)
        printf("my own test 8 passed, reverse int\n\n");
    else
        printf("**** FAILED **** test 8, reverse int\n\n");

  // test 9, reverse int
  n1 = 200;
  expected = 2;
  actual = reverseInt(n1); 
  printf("Test 9 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf(" my own passed test 9, reverse int\n\n");
  else 
     printf("**** FAILED **** test 9, reverse int\n\n");

  int n10 = 9600;
  expected = 69;

    actual = reverseInt(n10);
    printf("Test 9 reverse int: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)
        printf("my own passed test 9, reverse int\n\n");
    else
        printf("**** FAILED **** test 9, reverse int\n\n");

  // test 10, reverse int
  n1 = -96969600;
  expected = -696969;
  actual = reverseInt(n1); 
  printf("Test 10 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)
     printf("my own passed test 10, reverse int\n");
  else 
     printf("**** FAILED **** test 10, reverse int\n");

  int n11 = -10003;
  expected = -30001;
    actual = reverseInt(n11);
    printf("Test 10 reverse int: expected value: %d, actual value: %d\n", expected, actual);

    if(expected == actual)
        printf("my own passed test 10, reverse int\n");
    else
        printf("**** FAILED **** test 10, reverse int\n");


}

