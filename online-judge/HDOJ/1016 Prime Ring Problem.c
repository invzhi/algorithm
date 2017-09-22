#include <stdio.h>
#include <string.h>

int n;
int vis[19];
int ring[19] = {1};
int prime[40];

void initPrime() {
	int i, j;
	for (i = 2; i < 40; i++) prime[i] = 1;
	for (i = 2; i * i < 40; i++) {
		if (prime[i]) {
			for (j = i + i; j < 40; j += i) prime[j] = 0;
		}
	}
}

int isPrime(int num) {
	return prime[num];
}

void DFS(int cur) {
	int i;
	if (cur == n && isPrime(ring[n - 1] + ring[0])) {
		for (i = 0; i < n - 1; i++) printf("%d ", ring[i]);
		printf("%d\n", ring[i]);
	} else {
		for (i = 2; i <= n; i++) {
			if (!vis[i] && isPrime(ring[cur - 1] + i)) {
				ring[cur] = i;
				vis[i] = 1;
				DFS(cur + 1);
				vis[i] = 0;
			}
		}
	}
}

int main() {
	int i = 1;
	initPrime();
	while (scanf("%d", &n) == 1) {
		memset(vis, 0, sizeof(vis));
		printf("Case %d:\n", i++);
		DFS(1);
		printf("\n");
	}
	return 0;
}
