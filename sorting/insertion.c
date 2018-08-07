#include <stdio.h>
#include <assert.h>
#include "utils.h"

#define N 20

void insertion_sort(int a[], int n) {
	int exchanges = 0;
	for (int i = n - 1; i > 0; i--) {
		if (a[i] < a[i - 1]) {
			exch(&a[i], &a[i - 1]);
			exchanges++;
		}
	}
	if (exchanges == 0) return;

	int j, t;
	for (int i = 1; i < n; i++) {
		t = a[i];
		for (j = i; a[j - 1] > t; j--) {
			a[j] = a[j - 1];
		}
		a[j] = t;
	}
}

int main(int argc, char const *argv[])
{
	int a[N];
	generate_array(a, N);
	print_array(a, N);
	insertion_sort(a, N);
	print_array(a, N);
	assert(is_sorted(a, N));
	return 0;
}
