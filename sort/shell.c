#include <stdio.h>
#include "utils.h"

#define N 20

void shell_sort(int a[], int length) {
	int j, t;
	int h = 1;
	while (h < length / 3) {
		h = 3*h + 1;
	}
	while (h >= 1) {
		for (int i = h; i < N; i++) {
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
	printf(is_sorted(a, N) ? "Sort Success\n" : "Sort Error\n");
	return 0;
}
