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

void merge_bu_sort(int a[], int n) {
	int* t = (int*)malloc(sizeof(int) * n);
	if (t == NULL) {
		printf("malloc fail\n");
		return;
	}
	int mid, hi;
	int end = n - 1;
	for (int l = 1; l < n; l += l) {
		for (int lo = 0; lo < n - l; lo += l+l) {
			mid = lo + l - 1;
			hi = lo + l + l - 1;
			hi = hi < end ? hi : end;
			if (a[mid] >= a[mid + 1]) {
				// merge(a, t, lo, mid, hi);
				quick_merge(a, t, lo, mid, hi);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int a[N];
	generate_array(a, N);
	print_array(a, N);
	merge_bu_sort(a, N);
	print_array(a, N);
	assert(is_sorted(a, N));
	return 0;
}
