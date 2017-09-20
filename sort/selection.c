#include <stdio.h>
#include <assert.h>
#include "utils.h"

#define N 20

void selection_sort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int min_index = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[min_index]) {
				min_index = j;
			}
		}
		exch(&a[min_index], &a[i]);
	}
}

int main(int argc, char const *argv[])
{
	int a[N];
	generate_array(a, N);
	print_array(a, N);
	selection_sort(a, N);
	print_array(a, N);
	assert(is_sorted(a, N));
	return 0;
}
