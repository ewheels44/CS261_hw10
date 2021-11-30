
#include <iostream>
using namespace std;

void XSort(int list[], int n)
// Exchange sort
{
int min, tmp, i, j, min_j;
// Scan the list from the left to the right
for (i=0; i<n-1; i++) {
// Remember the item at position i
min = list[i]; min_j = i;
// Check the list to the right of position i for any smaller items
for (j=i+1; j<n; j++) {
if (list[j] < min) {
// Remember where this smaller item is
min = list[j]; min_j = j;
}
}
// Swap the item at position i with the smallest item found to the right
if(list[i] != list[min_j]) {
tmp = list[min_j]; list[min_j] = list[i];
list[i] = tmp;
}
}
}
