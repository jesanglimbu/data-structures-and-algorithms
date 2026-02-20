#include "bubblesort.h"
#include <stdbool.h>

void bubble_sort(int arr[], size_t len)
{
	size_t i = 0;
	bool swapped = true;

	while (swapped && i < len) {
		swapped = false;
		for (size_t j = 0; j < len-1; j++) {
			if (arr[j] > arr[j+1]) {
				int tmp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tmp;
				swapped = true;
			}
		}
		i++;
	}
			
}
