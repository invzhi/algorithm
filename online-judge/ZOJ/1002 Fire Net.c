#include <stdio.h>

int n, max;
char map[5][5];

int isPlace(int x, int y) {
	if (map[x][y] != '.') return 0;
	int i;
	for (i = x - 1; i >= 0; i--) {
		if (map[i][y] == 'X') break;
		if (map[i][y] == 'O') return 0;
	}
	for (i = y - 1; i >= 0; i--) {
		if (map[x][i] == 'X') break;
		if (map[x][i] == 'O') return 0;
	}
	return 1;
}

void DFS(int cur, int pos) {
	if (pos == n * n) {
		if (cur > max) max = cur;
		return;
	}
	int i = pos / n, j = pos % n;
	if (isPlace(i, j)) {
		map[i][j] = 'O';
		DFS(cur + 1, pos + 1);
		map[i][j] = '.';
	}
	DFS(cur, pos + 1);
}

int main() {
	while (scanf("%d", &n) == 1 && n) {
		int i;
		for (i = 0; i < n; i++) scanf("%s", map[i]);
		max = 0;
		DFS(0, 0);
		printf("%d\n", max);
	}
	return 0;
}