#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	return *(int*)b - *(int*)a;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int a, b; // m, n, m >= n
	for (int i = 1; i*i <= n; i++) {
		if (n % i == 0) {
			b = i;
			a = n / b;
		}
	}

	int num[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	qsort(num, n, sizeof(int), cmp);

	int matrix[a][b];
	for (int i = 0, j = 0, k = 0, d = 0; k < n; i++, j++, d++) {
		if (j == b - 1 - d) {
			while (i <= a - 1 - d) {
				matrix[i++][j] = num[k++];
			}
		} else {
			while (j < b - 1 - d) {
				matrix[i][j++] = num[k++];
			}
			while (i < a - 1 - d) {
				matrix[i++][j] = num[k++];
			}
			while (j > d) {
				matrix[i][j--] = num[k++];
			}
			while (i > d) {
				matrix[i--][j] = num[k++];
			}
		}
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf(j == 0 ? "%d" : " %d", matrix[i][j]);
		}
		putchar('\n');
	}

	return 0;
}
