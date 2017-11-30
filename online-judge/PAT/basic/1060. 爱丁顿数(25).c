#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	return *(int*)b - *(int*)a;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int dis[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &dis[i]);
	}
	qsort(dis, n, sizeof(int), cmp);

	int haveRes = 0;
	for (int i = n; i > 0; i--) {
		if (dis[i-1] > i) {
			printf("%d", i);
			haveRes = 1;
			break;
		}
	}
	if (haveRes == 0) {
		putchar('0');
	}

	return 0;
}
