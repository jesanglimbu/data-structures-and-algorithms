#ifndef _MERGESORT_H_
#define _MERGESORT_H_

#include <stddef.h>

int *merge_sort(int arr[], size_t l, size_t r);
void subarray(int target[], int arr[], size_t l, size_t r);
int *merge(int a1[], size_t len1, int a2[], size_t len2);

#endif
