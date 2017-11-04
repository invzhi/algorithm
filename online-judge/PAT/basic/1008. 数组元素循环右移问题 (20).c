#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n, m; // 1 <= n <= 100, m >= 0
	scanf("%d %d", &n, &m);
	m %= n;

	int num[n];
	for (int i = m; i < n; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &num[i]);
	}

	printf("%d", num[0]);
	for (int i = 1; i < n; i++) {
		printf(" %d", num[i]);
	}
	return 0;
}
