#include "mergesort.h"
#include <stdlib.h>
#include <stdio.h>

#define null (void*)0

int *merge_sort(int arr[], size_t l, size_t r)
{
	size_t m = (r + l) / 2;
	if (r - l > 1) {
		// create subarrays
		size_t len1 = m - l;
		size_t len2 = r - m;

		int *a1 = (int *)malloc(len1 * sizeof(int));
		subarray(a1, arr, l, m);

		int *a2 = (int *)malloc(len2 * sizeof(int));
		subarray(a2, arr, m, r);

		// recursive call
		return merge(merge_sort(a1, 0, len1), len1, merge_sort(a2, 0, len2), len2);
	} else if (r - l == 1) {
		int *tmp = malloc(sizeof(int));
		tmp[0] = arr[l];
		return tmp;
	}

	return null;

}

void subarray(int target[], int arr[], size_t l, size_t r)
{
	size_t len = r - l;
	for (size_t i = 0; i < len; i++) {
		target[i] = arr[l+i];
	}
}

int *merge(int a1[], size_t len1, int a2[], size_t len2)
{
	size_t len = len1 + len2;
	size_t i, j, k;

	int *new_arr = (int*)malloc(len * sizeof(int));
	
	i = j = k = 0;
	while (i < len1 && j < len2) {
		if (a2[j] < a1[i]) {
			new_arr[k] = a2[j];
			j++;
		} else {
			new_arr[k] = a1[i];
			i++;
		}
		k++;
	}

	while (i < len1) {
		new_arr[k] = a1[i];
		i++;
		k++;
	}

	while (j < len2) {
		new_arr[k] = a2[j];
		j++;
		k++;
	}

	return new_arr;
}
