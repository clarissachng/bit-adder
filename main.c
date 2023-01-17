#include <stdio.h>

#define N 4 // Number of bits

// x, y, and r are arrays of 0s and 1s
// This function should add together the little endian binary
// arrays, x and y, outputting the answer to r
int binaryAdd(const int x[N], const int y[N], int r[N]) {
  int ci = 0; // Carry-in, should always be 0 or 1

  for (int i=0; i < N; i++) {
    const int foo = x[i] + y[i] + ci;
    r[i] = foo % 2;
    if (foo < 2) {
      ci = 0;
    } else {
      ci = 1;
    }
  }

  return ci;
}

/*-----------------------------------------------------------------------------
  Main function
-----------------------------------------------------------------------------*/

void printOutput(const int x[N], const int y[N], int r[N], const int ci);

int main() {
  // Little endian representation 
  // ie. less significant bits first
  // eg. 1000 = 1, 0100 = 2, 1100 = 3 etc.
  const int x[N] = {1,1,0,0}; // input one
  const int y[N] = {1,0,0,0}; // input two
  int r[N] = {0,0,0,0}; // output

  const int ci = binaryAdd(x,y,r);

  printOutput(x, y, r, ci);

  return 0;
}

/*-----------------------------------------------------------------------------
  Console printing functions
-----------------------------------------------------------------------------*/

void printBinaryConstLn(const int b[N]) {
  for(int i=0; i < N; i++) {
    printf("%d", b[i]);
  }
  printf("\n");
}

void printBinaryLn(int b[N]) {
  for(int i=0; i < N; i++) {
    printf("%d", b[i]);
  }
  printf("\n");
}

void printDividerLn(int n) {
  for(int i=0; i < n; i++) {
    printf("⎯");
  }
  printf("\n");
}

void printOutput(const int x[N], const int y[N], int r[N], const int ci) {
  printf("  ");
  printBinaryConstLn(x);
  printf("+ ");
  printBinaryConstLn(y);
  printDividerLn(N+2);
  printf("= ");
  printBinaryLn(r);
  printf("\nci = %d\n", ci);
}
