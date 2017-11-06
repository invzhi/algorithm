#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main(int argc, char const *argv[])
{
	int n, p; // 0 < n <= 10^5, 0 < p <= 10^9
	scanf("%d %d", &n, &p);

	int num[n];
	for (int i = 0; i < n ; i++) {
		scanf("%d", &num[i]);
	}
	qsort(num, n, sizeof(int), cmp);

	int max = 0;
	for (int head = 0, tail = 0; tail < n; head++) {
		while (tail < n && p >= (num[tail] - 1) / num[head] + 1) { // ceiling: avoid overflow
			tail++;
		}
		if (tail - head > max) {
			max = tail - head;
		}
	}
	printf("%d", max);

	return 0;
}
