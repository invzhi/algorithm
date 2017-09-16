#include <stdio.h>
#include "utils.h"

#define N 20

int compare_times = 0;
int exchange_times = 0;

void insertion_sort(int a[], int length) {
	int j, t;
	for (int i = 1; i < length; i++) {
		t = a[i];
		for (j = i; j > 0 && a[j - 1] > t; j--) {
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
	printf(is_sorted(a, N) ? "Sort Success\n" : "Sort Error\n");
	return 0;
}
