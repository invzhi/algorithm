#include <stdio.h>
#include "utils.h"

#define N 20

int partition(int a[], int lo, int hi) {
	int i = lo, j = hi + 1;
	int v = a[lo];
	while (1) {
		while (a[++i] < v) if (i == hi) break;
		while (a[--j] > v);
		if (i >= j) break;
		exch(&a[i], &a[j]);
	}
	exch(&a[lo], &a[j]);
	return j;
}

void sort(int a[], int lo, int hi) {
	if (lo >= hi) return;
	// if (hi - lo < 15) insertion_sort(a, lo, hi); return;
	int j = partition(a, lo, hi);
	sort(a, lo, j - 1);
	sort(a, j + 1, hi);
}

void quick_sort(int a[], int n) {
	sort(a, 0, n - 1);
}

int main(int argc, char const *argv[])
{	
	int a[N];
	generate_array(a, N);
	print_array(a, N);
	quick_sort(a, N);
	print_array(a, N);
	printf(is_sorted(a, N) ? "Sort Success\n" : "Sort Error\n");
	return 0;
}