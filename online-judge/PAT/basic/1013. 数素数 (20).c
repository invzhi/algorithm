#include <stdio.h>

#define N 10000

int main(int argc, char const *argv[])
{
	int m, n; // m <= n <= 10000
	scanf("%d %d", &m, &n);

	int primes[N] = {2, 3};
	int p = 2;
	for (int num = 5; p < n; num += 2) {
		int is_prime = 1;
		for (int i = 1; primes[i]*primes[i] <= num; i++) {
			if (num % primes[i] == 0) {
				is_prime = 0;
				break;
			}
		}
		if (is_prime) {
			primes[p++] = num;
		}
	}

	int l = n - m;
	for (int i = 0; i < l; i++) {
		printf("%d", primes[m-1+i]);
		printf(i % 10 == 9 ? "\n" : " ");
	}
	printf("%d", primes[n-1]);
	return 0;
}
