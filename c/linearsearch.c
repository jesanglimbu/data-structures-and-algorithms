#include "linearsearch.h"

int linear_search(int arr[], size_t size, int v)
{
	for (size_t i = 0; i < size; i++) {
		if (v == arr[i]) {
			return i;
		}
	}
	
	return -1;
}
