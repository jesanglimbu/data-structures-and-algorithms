#include "selectionsort.h"

void selection_sort(int arr[], size_t len) {
	int low;
	for (size_t i = 0; i < len; i++) {
		low = i;
		for (size_t j = i+1; j < len; j++) {
			if (arr[j] < arr[low]) {
				low = j;
			}
		}
		int tmp = arr[low];
		arr[low] = arr[i];
		arr[i] = tmp;
	}
}
