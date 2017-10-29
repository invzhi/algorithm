#include <stdio.h>
#include <string.h>

// Sample Input
// K N1 aN1 N2 aN2 ... NK aNK
// 2 1 2.4 0 3.2
// 2 2 1.5 1 0.5
// Sample Output
// 3 2 1.5 1 2.9 0 3.2

// 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.

#define N 1001

int main() {
	float map[N];
	int m, n, k;
	float v;
	memset(map, 0, sizeof(float) * N);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%f", &k, &v);
		map[k] += v;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%f", &k, &v);
		map[k] += v;
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (map[i] != 0.0) {
			cnt++;
		}
	}
	printf("%d", cnt);
	for (int i = N - 1; i >= 0; i--) {
		if (map[i] != 0.0) {
			printf(" %d %.1f", i, map[i]);
		}
	}
	return 0;
}
