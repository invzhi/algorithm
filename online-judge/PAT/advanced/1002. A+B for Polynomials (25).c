#include <stdio.h>
#include <string.h>

// Sample Input
// K N1 aN1 N2 aN2 ... NK aNK
// 2 1 2.4 0 3.2
// 2 2 1.5 1 0.5
// Sample Output
// 3 2 1.5 1 2.9 0 3.2

// 1 <= K <= 10，0 <= NK < ... < N2 < N1 <= 1000

#define N 1001

int main() {
	float map[N];
	memset(map, 0, sizeof(map));

	float a;
	int n, k;

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d%f", &n, &a);
		map[n] += a;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d%f", &n, &a);
		map[n] += a;
	}

	int last, cnt = 0;
	for (int i = 0; i < N; i++) {
		if (map[i] != 0.0) {
			cnt++;
			last = i;
		}
	}

	printf("%d", cnt);
	for (int i = last; i >= 0; i--) {
		if (map[i] != 0.0) {
			printf(" %d %.1f", i, map[i]);
		}
	}

	return 0;
}
