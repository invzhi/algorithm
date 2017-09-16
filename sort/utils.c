#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_array(int a[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
	}
}

void print_array(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%2d ", a[i]);
	}
	printf("\n");
}

int is_sorted(int a[], int n) {
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			return 0;
		}
	}
	return 1;
}

void report(int number, int compare_times, int exchange_times) {
	printf("Number:   %d\n", number);
	printf("Compare : %d\n", compare_times);
	printf("Exchange: %d\n", exchange_times);
}
