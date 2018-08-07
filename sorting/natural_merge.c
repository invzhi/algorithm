#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "utils.h"

#define N 20

void quick_merge(int a[], int t[], int lo, int mid, int hi) {
	for (int i = 0; i <= mid; i++) {
		t[i] = a[i];
	}
	for (int i = hi; i > mid; i--) {
		t[i] = a[hi - i + mid + 1];
	}

	int i = lo, j = hi;
	for (int k = lo; k <= hi; k++) {
		if (t[i] < t[j]) a[k] = t[i++];
		else             a[k] = t[j--];
	}
}

void merge(int a[], int t[], int lo, int mid, int hi) {
	int i = lo, j = mid + 1;
	for (int k = lo; k <= hi; k++) {
		t[k] = a[k];
	}
	for (int k = lo; k <= hi; k++) {
		if (i > mid)          a[k] = t[j++];
		else if (j > hi)      a[k] = t[i++];
		else if (t[i] < t[j]) a[k] = t[i++];
		else                  a[k] = t[j++];
	}
}


int point(int a[], int p[], int n) {
	int j = 0;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			p[j++] = i;
		}
	}
	return j;
}

void natural_merge_sort(int a[], int n) {
	int* t = (int*)malloc(sizeof(int) * n);
	int* p = (int*)malloc(sizeof(int) * n);
	if (t == NULL || p == NULL) {
		printf("malloc fail\n");
		return;
	}

	int pn = point(a, p, n); // find all reverse point to p[]
	for (int step = 1; step - 1 < pn; step += step) {
		int lo = 0, hi; // mid is index
		for (int mid = step - 1; mid < pn; mid += step+step) {
			hi = mid + step < pn ? p[mid + step] : n - 1;
			// merge(a, t, lo, p[mid], hi);
			quick_merge(a, t, lo, p[mid], hi);
			lo = hi + 1;
		}
	}
}

int main(int argc, char const *argv[])
{
	int a[N];
	generate_array(a, N);
	print_array(a, N);
	natural_merge_sort(a, N);
	print_array(a, N);
	assert(is_sorted(a, N));
	return 0;
}
