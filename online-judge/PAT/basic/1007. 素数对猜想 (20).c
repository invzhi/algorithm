#include <stdio.h>

void eratosthenes(int primes[], int n) {
	for (int i = 0; i <= n; i++) {
		primes[i] = i;
	}
	for (int p = 2; p*p <= n; p++) {
		if (primes[p]) {
			for (int i = p+p; i <= n; i += p) {
				primes[i] = 0;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int primes[n+1];
	eratosthenes(primes, n);

	int couple = 0;
	for (int i = 3; i+2 <= n; i += 2) {
		if (primes[i] > 1 && primes[i+2] > 1) {
			couple++;
		}
	}
	printf("%d", couple);
	return 0;
}
