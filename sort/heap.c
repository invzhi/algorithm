#include <stdio.h>
#include <assert.h>
#include "utils.h"

#define N 20

void sink(int a[], int f, int b) {
	while (2*f + 1 < b) {
		int c = 2*f + 1;
		if (c+1 < b && a[c] < a[c+1]) {
			c++;
		}
		if (a[f] >= a[c]) {
			break;
		}
		exch(&a[c], &a[f]);
		f = c;
	}
}

void heap_sort(int a[], int n) {
	for (int i = n/2 - 1; i >=0; i--) {
		sink(a, i, n);
	}
	for (int i = n - 1; i > 0; i--) {
		exch(&a[i], &a[0]);
		sink(a, 0, i);
	}
}

int main(int argc, char const *argv[])
{
	int a[N];
	generate_array(a, N);
	print_array(a, N);
	heap_sort(a, N);
	print_array(a, N);
	assert(is_sorted(a, N));
	return 0;
}
