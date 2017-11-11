#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int num[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	int lmax[n];
	lmax[0] = num[0];
	for (int i = 1; i < n; i++) {
		lmax[i] = (num[i] > lmax[i-1] ? num[i] : lmax[i-1]);
	}

	int rmin[n];
	rmin[n-1] = num[n-1];
	for (int i = n - 2; i >= 0; i--) {
		rmin[i] = (num[i] < rmin[i+1] ? num[i] : rmin[i+1]);
	}

	int cnt = 0;
	int pivot[n];
	for (int i = 0; i < n; i++) {
		if (num[i] >= lmax[i] && num[i] <= rmin[i]) {
			pivot[cnt++] = num[i];
		}
	}

	printf("%d\n", cnt);
	if (cnt > 0) {
		printf("%d", pivot[0]);
		for (int i = 1; i < cnt; i++) {
			printf(" %d", pivot[i]);
		}
	}
	putchar('\n');

	return 0;
}
