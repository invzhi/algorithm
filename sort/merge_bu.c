#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "utils.h"

#define N 20

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

void merge_bu_sort(int a[], int length) {
	int* t = (int*)malloc(sizeof(int) * length);
	if (t == NULL) {
		printf("malloc fail\n");
		return;
	}
	int mid, hi;
	int end = length - 1;
	for (int l = 1; l < length; l += l) {
		for (int lo = 0; lo < length - l; lo += l+l) {
			mid = lo + l - 1;
			hi = lo + l + l - 1;
			hi = hi < end ? hi : end;
			if (a[mid] >= a[mid + 1]) {
				merge(a, t, lo, mid, hi);
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
