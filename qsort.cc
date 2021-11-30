
#include <iostream>
using namespace std;
int Partition(int list[], int lo, int hi);
void QSort(int list[], int lo, int hi)
// QuickSort - this simple version assumes no repeated items in the list
{
int k;
if (lo < hi) {
// Partition the list into two sub-lists
k = Partition(list, lo, hi);
// Now every item left of position k is smaller than the item at k,
// while every item right of position k is larger than the item at k
QSort(list, lo, k-1); // sort the sublist to the left of k
QSort(list, k+1, hi); // sort the sublist to the right of k
}
}
int Partition(int list[], int lo, int hi)
// Partition function for QuickSort
{
int x, tmp;
// Pick an arbitrary key, say half way through the list
x = list[(lo+hi)/2];
// Now swap items until every item to the left of the key is smaller than
// the key, and every item to the right of the key is larger than the key
while (lo < hi) {
// Scan from the right until we find an item smaller than the key
while ( (lo < hi) && (x < list[hi]) ) hi--;
// Scan from the left until we find an item larger than the key
while ( (lo < hi) && (x > list[lo]) ) lo++;
// Swap the two items we've discovered on the wrong side of the key
tmp = list[lo]; list[lo] = list[hi]; list[hi] = tmp;
}
return lo; // this is where the key is now
}
