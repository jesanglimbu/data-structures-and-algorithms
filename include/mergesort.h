#ifndef _MERGESORT_H_
#define _MERGESORT_H_

#include <stddef.h>

/* Method for the actual sorting algorithm */
int *mergesort(int arr[], size_t l, size_t r);

/* Method to "split" the array */
void subarray(int target[], int arr[], size_t l, size_t r);

/* Method to merge two arrays */
int *merge(int a1[], size_t len1, int a2[], size_t len2);

#endif
