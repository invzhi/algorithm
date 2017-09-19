#include <stdio.h>

#define N 100

void eratosthenes(int a[], int n) {
	a[0] = a[1] = 0;
	a[2] = 1;
	for (int i = 3; i <= n; i += 2) {
		a[i] = 1;
		a[i + 1] = 0;
	}
	for (int i = 2; i < n; i++) {
		if (a[i]) {
			for (int j = i+i; j <= n; j += i) {
				a[j] = 0;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int a[N + 1];
	eratosthenes(a, N);
	for (int i = 0; i <= N; i++) {
		if (a[i]) {
			printf("%3d", i);
		}
	}
	printf("\n");
	return 0;
}