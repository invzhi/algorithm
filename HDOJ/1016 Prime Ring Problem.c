#include <stdio.h>
#include <string.h>

int n;
int vis[19];
int ring[19] = {1};

int isPrime(int num) {
	int i;
	for (i = 2; i * i <= num; i++) {
		if (num % i == 0) return 0;
	}
	return 1;
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
	while (scanf("%d", &n) == 1) {
		memset(vis, 0, sizeof(vis));
		printf("Case %d:\n", i++);
		DFS(1);
		printf("\n");
	}
	return 0;
}