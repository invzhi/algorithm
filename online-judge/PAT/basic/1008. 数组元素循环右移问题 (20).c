#include <stdio.h>

#define N 100

int main(int argc, char const *argv[])
{
	int n, m; // 1 <= n <= 100, m >= 0
	scanf("%d %d", &n, &m);

	int num[n];
	for (int i = 0; i < n; i++) {
		int index = (i + m) % n;
		scanf("%d", &num[index]);
	}

	for (int i = 0; i < n - 1; i++) {
		printf("%d ", num[i]);
	}
	printf("%d", num[n-1]);
	return 0;
}
