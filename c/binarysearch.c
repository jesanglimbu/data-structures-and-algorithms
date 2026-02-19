#include "binarysearch.h"

int binary_search(int arr[], size_t len, int v)
{
	size_t l = 0;
	size_t r = len-1;
	int mid;
	while (r >= l) {
		mid = (l + r) / 2;
		if (arr[mid] == v) {
			return mid;
		} else if (arr[mid] < v) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}

	return -1;
}
