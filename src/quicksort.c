#include "quicksort.h"
#include "mergesort.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void
quick_sort(int arr[], int l, int r)
{
	if (l < r) {
		int pivot = partition(arr, l, r);
		quick_sort(arr, l, pivot);
		quick_sort(arr, pivot+1, r);
	}
}


/* In this implementation, we use Hoare's partitioning algorithm. */
int
partition(int arr[], int l, int r)
{
	/* Initialize left and right pointers */
	int left, right;
	left = l;
	right = r;
	int pivot = arr[left]; /* Our pivot will be the first element of the (sub)array */
	
	while (left < right) {
		if (arr[left] >= pivot && arr[right] < pivot) {
			/* Swap left and right elements */
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}

		if (arr[left] < pivot) {
			left++;
		} else {
			right--;
		}
	}

	/*
	  Some cases to cover for the partition and
	  the sorting to work correctly.
	*/
	if (left <= 0)
		return 0;
	
	if (arr[left] >= pivot && left > l)
		return left-1;

	return left;
}
	       
