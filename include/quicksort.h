#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include <stddef.h>

/* Method for the recursive sorting */
void quick_sort(int arr[], int left, int right);

/* Method for the partitioning used in the algorithm. */
int partition(int arr[], int left, int right);

#endif
