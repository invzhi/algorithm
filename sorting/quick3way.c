#include <stdio.h>
#include <assert.h>
#include "utils.h"

#define N 20

void sort(int a[], int lo, int hi) {
	if (lo >= hi) return;
	// if (hi - lo < 15) insertion_sort(a, lo, hi); return;
	int lt = lo, i = lo + 1, gt = hi;
	int v = a[lo];
	while (i <= gt) {
		if (a[i] < v) {
			exch(&a[i], &a[lt]);
			lt++;
			i++;
		} else if (a[i] > v) {
			exch(&a[i], &a[gt]);
			gt--;
		} else {
			i++;
		}
	}
	sort(a, lo, lt - 1);
	sort(a, gt + 1, hi);
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
