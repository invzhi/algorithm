#include <stdio.h>

#define N 10000

int main(int argc, char const *argv[])
{
	int m, n;
	scanf("%d %d", &m, &n);

	int primes[N] = {2, 3};
	int j = 2;
	for (int p = 5; j < n; p += 2) {
		int is_prime = 1;
		for (int i = 1; primes[i]*primes[i] <= p; i++) {
			if (p % primes[i] == 0) {
				is_prime = 0;
				break;
			}
		}
		if (is_prime) {
			primes[j++] = p;
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
