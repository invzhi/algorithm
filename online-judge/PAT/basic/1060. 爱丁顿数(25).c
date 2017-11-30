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

	int e;
	for (e = n; e > 0; e--) {
		if (dis[e-1] > e) {
			break;
		}
	}
	printf("%d", e);

	return 0;
}
