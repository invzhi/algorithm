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

void report(int number, int compare_times, int exchange_times) {
	printf("Number:   %d\n", number);
	printf("Compare : %d\n", compare_times);
	printf("Exchange: %d\n", exchange_times);
}
