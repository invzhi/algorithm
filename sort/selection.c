#include <stdio.h>
#include "utils.h"

#define N 20

void selection_sort(int a[], int length) {
	for (int i = 0; i < length; i++) {
		int min_index = i;
		for (int j = i; j < length; j++) {
			if (a[j] < a[min_index]) {
				min_index = j;
			}
		}
		void exch(int* a, int* b) {
			int t = *a;
			*a = *b;
			*b = t;
		}
		exch(&a[min_index], &a[i]);
	}
}

int main(int argc, char const *argv[])
{
	int a[N];
	generate_array(a, N);
	print_array(a, N);
	selection_sort(a, N);
	print_array(a, N);
	printf(is_sorted(a, N) ? "Sort Success\n" : "Sort Error\n");
	return 0;
}
