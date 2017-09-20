#include <stdio.h>
#include "utils.h"

#define N 20

void binary_insertion_sort(int a[], int length) {
	int t;
	int lo, mid, hi;
	for (int i = 1; i < length; i++) {
		t = a[i];
		lo = 0;
		hi = i;
		while (lo < hi) {
			mid = lo + (hi - lo) / 2;	
			if (a[mid] <= t) {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}
		for (int j = i; j > lo; j--) {
			a[j] = a[j - 1];
		}
		a[lo] = t;
	}
}

int main(int argc, char const *argv[])
{
	int a[N];
	generate_array(a, N);
	print_array(a, N);
	binary_insertion_sort(a, N);
	print_array(a, N);
	printf(is_sorted(a, N) ? "Sort Success\n" : "Sort Error\n");
	return 0;
}
