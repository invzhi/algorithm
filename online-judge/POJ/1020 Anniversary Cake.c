#include <stdio.h>
#include <string.h>

int s, n;
char num[11], C[41];

int DFS(int cur) {
	if (cur == n) return 1;
	int i, j, r, minC = 41;
	for (i = 1; i <= s; i++) {
		if (C[i] < minC) {
			minC = C[i];
			r = i;
		}
	}
	for (i = 10; i > 0; i--) {
		if (!num[i]) continue;
		if (minC + i <= s && r + i - 1 <= s) {
			int ok = 1;
			for (j = 1; j < i; j++) {
				if (C[r + j] > C[r]) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				for (j = 0; j < i; j++) C[r + j] += i;
				num[i]--;
				if (DFS(cur + 1)) return 1;
				num[i]++;
				for (j = 0; j < i; j++) C[r + j] -= i;
			}
		}
	}
	return 0;
}

int solve() {
	scanf("%d%d", &s, &n);
	memset(num, 0, sizeof(num));
	int i, sum;
	for (i = sum = 0; i < n; i++) {
		int l;
		scanf("%d", &l);
		num[l]++;
		sum += l * l;
	}
	memset(C, 0, sizeof(C));
	return sum == s * s ? DFS(0) : 0;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) puts(solve() ? "KHOOOOB!" : "HUTUTU!");
	return 0;
}
