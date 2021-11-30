#include "inst_compact.h"
#include <iostream>
using namespace std;

const int matrixSize = 100;
const int blockingFactor = 20;
int a[matrixSize][matrixSize];
int b[matrixSize][matrixSize];
int c[matrixSize][matrixSize];

int main() {
  int i, j, k, jj, kk, r;
  // Initialise the matrices arbitrarily
  for (i = 0; i < matrixSize; i++) {
    for (j = 0; j < matrixSize; j++) {
      b[i][j] = i + j;
      c[i][j] = i - j;
      a[i][j] = 0;
    }
  }

  // Work out a = b * c, using a blocking algorithm
  int row, col, rowcol, prod = 0;
  for (row = 0; row < matrixSize; row++) {
    for(col = 0; col < matrixSize; col++){
      for(rowcol = 0; rowcol < matrixSize; rowcol++){
        INST_R(b[row][rowcol]);
        INST_R(c[rowcol][col]);
        prod = prod + b[row][rowcol] * c[rowcol][col]; 
      }
      INST_R(a[row][col]);
      a[row][col] = prod;
      INST_W(a[row][col]);
      prod = 0;
    }
  }

  // Display the product
  // for (i = 0; i < matrixSize; i++) {
  //   for (j = 0; j < matrixSize; j++) {
  //     cerr << a[i][j] << ' ';
  //   }
  //   cerr << endl;
  // }
  return 0;
}
