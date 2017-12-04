#include <stdio.h>
#include <string.h>

#define N  1001
#define DN 2001

int main() {
	float x[N];
	memset(x, 0, sizeof(x));

	int k, max_n, min_n;

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		float a;
		int n;
		scanf("%d %f", &n, &a);
		x[n] = a;
		if (i == 0) {
			max_n = n;
		} else if (i == k - 1) {
			min_n = n;
		}
	}

	float y[DN];
	memset(y, 0, sizeof(y));

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		float a;
		int n;
		scanf("%d %f", &n, &a);
		for (int i = min_n; i <= max_n; i++) {
			if (x[i] != 0.0) {
				y[i+n] += a * x[i];
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < DN; i++) {
		if (y[i] != 0.0) {
			cnt++;
			max_n = i;
		}
	}

	printf("%d", cnt);
	for (int i = max_n; i >= 0; i--) {
		if (y[i] != 0.0) {
			printf(" %d %.1f", i, y[i]);
		}
	}

	return 0;
}
