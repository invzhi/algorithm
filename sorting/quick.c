#include <stdio.h>
#include <assert.h>
#include "utils.h"

#define INSERTION_SORT_CUTOFF 8
#define N 100

int median3(int a[], int lo, int hi) {
	int mid = (lo + hi) / 2;
	if (a[lo] > a[mid]) exch(&a[lo], &a[mid]);
	if (a[lo] > a[hi])  exch(&a[lo], &a[hi]);
	if (a[mid] > a[hi]) exch(&a[mid], &a[hi]);
	exch(&a[mid], &a[lo + 1]);
	return a[lo + 1];
}

int partition(int a[], int lo, int hi) {
	int pivot = median3(a, lo, hi);
	int i = lo + 1, j = hi;
	while (1) {
		while (a[++i] < pivot);
		while (a[--j] > pivot);
		if (i >= j) break;
		exch(&a[i], &a[j]);
	}
	exch(&a[lo + 1], &a[j]);
	return j;
}

void insertion_sort(int a[], int lo, int hi) {
	int exchanges = 0;
	for (int i = hi; i > lo; i--) {
		if (a[i] < a[i - 1]) {
			exch(&a[i], &a[i - 1]);
			exchanges++;
		}
	}
	if (exchanges == 0) return;

	int j, t;
	for (int i = lo + 1; i <= hi; i++) {
		t = a[i];
		for (j = i; a[j - 1] > t; j--) {
			a[j] = a[j - 1];
		}
		a[j] = t;
	}
}

void sort(int a[], int lo, int hi) {
	// if (lo >= hi) return;
	if (hi - lo < INSERTION_SORT_CUTOFF) {
		insertion_sort(a, lo, hi);
		return;
	}
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
	assert(is_sorted(a, N));
	return 0;
}
