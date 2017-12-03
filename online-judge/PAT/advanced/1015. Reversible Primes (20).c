#include <stdio.h>

#define N 100000

void eratosthenes(int is_prime[]) {
	for (int i = 0; i < N; i++) {
		is_prime[i] = i;
	}
	for (int num = 2; num*num <= N; num++) {
		if (is_prime[num]) {
			for (int i = num+num; i < N; i += num) {
				is_prime[i] = 0;
			}
		}
	}
}

int reverse(int num, int radix) {
	int reverse_num = 0;
	while (num > 0) {
		reverse_num = reverse_num * radix + num % radix;
		num /= radix;
	}
	return reverse_num;
}

int main() {
	int is_prime[N];
	eratosthenes(is_prime);

	int n, d;
	while (scanf("%d %d", &n, &d) == 2) {
		int rn = reverse(n, d);
		if (is_prime[n] > 1 && is_prime[rn] > 1) {
			puts("Yes");
		} else {
			puts("No");
		}
	}

	return 0;
}
