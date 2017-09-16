#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, cnt, initLen;
int length[64];
bool vis[64];

bool cmp(int a, int b) {
	return a > b;
}

bool DFS(int cur, int len, int s) {
	if (cnt == cur) return true;
	int same = -1;
	for (int i = s; i < n; i++) {
		if (vis[i] || length[i] == same) continue;
		vis[i] = true;
		if (len + length[i] < initLen) {
			if (DFS(cur, len + length[i], i + 1)) return true;
			else same = length[i];
		} else if (len + length[i] == initLen) {
			if (DFS(cur + 1, 0, 0)) return true;
			else same = length[i];
		}
		vis[i] = false;
		if (len == 0) break;
	}
	return false;
}

int main() {
	while (scanf("%d", &n) && n) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &length[i]);
			sum += length[i];
		}
		sort(length, length + n, cmp);
		int no = 1;
		for (initLen = length[0]; initLen <= sum / 2; initLen++) {
			if (sum % initLen) continue;
			cnt = sum / initLen;
			memset(vis, false, sizeof(vis));
			if (DFS(1, 0, 0)) {
				printf("%d\n", initLen);
				no = 0;
				break;
			}
		}
		if (no) printf("%d\n", sum);
	}
	return 0;
}