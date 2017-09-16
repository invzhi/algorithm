#include <stdio.h>
#include "utils.h"

#define N 20

int compare_times = 0;
int exchange_times = 0;

void selection_sort(int a[], int length) {
	for (int i = 0; i < length; i++) {
		int min_index = i;
		for (int j = i; j < length; j++) {
			if (a[j] < a[min_index]) {
				compare_times++;
				min_index = j;
			}
		}
		void exch(int* a, int* b) {
			exchange_times++;
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
	report(N, compare_times, exchange_times);
	return 0;
}
