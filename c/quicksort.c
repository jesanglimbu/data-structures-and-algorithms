#include "quicksort.h"
#include "mergesort.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void quick_sort(int arr[], int l, int r) {
	if (l < r) {
		int pivot = partition(arr, l, r);
		quick_sort(arr, l, pivot);
		quick_sort(arr, pivot+1, r);
	}
}

int partition(int arr[], int l, int r) {
	int left, right;
	left = l;
	right = r;
	int pivot = arr[left];
	
	while (left < right) {
		if (arr[left] >= pivot && arr[right] < pivot) {
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

	if (left <= 0)
		return 0;
	
	if (arr[left] >= pivot && left > l)
		return left-1;

	return left;
}
	       
