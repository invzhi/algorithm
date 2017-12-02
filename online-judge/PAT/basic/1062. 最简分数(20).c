#include <stdio.h>

int getGcd(int a, int b) {
	if (b) while ((a %= b) && (b %= a));
	return a + b;
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int main(int argc, char const *argv[])
{
	int n1, m1, n2, m2, k;
	scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);

	if (n1 < 0) {
		n1 = -n1;
		m1 = -m1;
	}
	if (n2 < 0) {
		n2 = -n2;
		m2 = -m2;
	}

	if (n1*m2 > n2*m1) {
		swap(&n1, &n2);
		swap(&m1, &m2);
	}

	int a = k * n1 / m1 + 1;

	for (int i = a, first = 1; i*m2 < k*n2; i++) {
		if (getGcd(i, k) == 1) {
			printf("%s%d/%d", first ? "" : " ", i, k);
			first = 0;
		}
	}

	return 0;
}
