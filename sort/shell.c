#include <stdio.h>
#include <assert.h>
#include "utils.h"

#define N 20

void shell_sort(int a[], int n) {
	int h = 1;
	while (h < n / 3) {
		h = 3*h + 1;
	}
	while (h >= 1) {
		int j, t;
		for (int i = h; i < n; i++) {
			t = a[i];
			for (j = i; j >= h && a[j - h] > t; j -= h) {
				a[j] = a[j - h];
			}
			a[j] = t;
		}
		h /= 3;
	}
}

int main(int argc, char const *argv[])
{
	int a[N];
	generate_array(a, N);
	print_array(a, N);
	shell_sort(a, N);
	print_array(a, N);
	assert(is_sorted(a, N));
	return 0;
}
