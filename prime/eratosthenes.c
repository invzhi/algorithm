#include <stdio.h>
#include <math.h>
#include <assert.h>

#define N 100

void eratosthenes(int primes[], int n) {
	for (int i = 0; i <= n; i++) {
		primes[i] = i;
	}
	for (int prime = 2; prime*prime <= n; prime++) {
		if (primes[prime]) {
			for (int index = prime+prime; index <= n; index += prime) {
				primes[index] = 0;
			}
		}
	}
}

int is_prime(int num) {
	for (int i = 2; i*i <= num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int n = N * log(N) * 1.15; // p(n) = n * ln(n)
	int primes[n + 1];
	eratosthenes(primes, n);

	printf("n*ln(n) = %d\n", n);
	for (int i = 2, j = 0; i <= n; i++) {
		if (primes[i] > 1) {
			j++;
			assert(is_prime(i));
			printf("%3d: %3d\n", j, i);
		}
	}
	return 0;
}