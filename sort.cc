#include "inst_none.h"
#include <iostream>
#include <stdlib.h>
#include "xsort.cc"
#include "qsort.cc"
using namespace std;

const int listSize = 10000;
int l[listSize];
int main()
{
int i, tmp, i1, i2;
// Generate a list with no repeated numbers
for (i=0; i<listSize; i++) l[i] = i;
// Scramble the numbers thoroughly
for (i=0; i<listSize; i++) {
i1 = rand() % listSize; i2 = rand() % listSize;
tmp = l[i1]; l[i1] = l[i2]; l[i2] = tmp;
}
// Sort the list by exchange sort or QuickSort - comment out the
// one you don't want to use
XSort(l, listSize);
// QSort(l, 0, listSize-1);
return 0; // return success code
}