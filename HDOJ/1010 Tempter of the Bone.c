#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dx, dy, flag, N, M, T;
int vis[6][6];
int maze[6][6];
int move[4][2] = {{0, 1}, {1, -1}, {-1, -1}, {-1, 1}};

void DFS(int x, int y, int cur) {
	vis[x][y] = 1;
	if (x == dx && y == dy) {
		if (cur == T) flag = 1;
		return;
	}
	if (cur >= T) {
		flag = 0;
		return;
	}
	int i;
	for(i = 0; i < 4; i++) {
		x += move[i][0];
		y += move[i][1];
		if(x >= 0 && x < N && y >= 0 && y < M && maze[x][y] != 'X' && !vis[x][y]) {
			DFS(x, y, cur + 1);
			if(flag) return;
			vis[x][y] = 0;
		}
	}
}

int main() {
	while (scanf("%d%d%d", &N, &M, &T) == 3 && (N || M || T)) {
		int i, j, sx, sy;
		getchar();
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				scanf("%c", &maze[i][j]);
				if (maze[i][j] == 'S') {
					sx = i;
					sy = j;
				} else if (maze[i][j] == 'D') {
					dx = i;
					dy = j;
				}
			}
			getchar();
		}
		if (abs(sx - dx) + abs(sy - dy) > T || (sx + sy + dx + dy + T) & 1) {
			puts("NO");
			continue;
		}
		flag = 0;
		memset(vis, 0, sizeof(vis));
		DFS(sx, sy, 0);
		puts(flag ? "YES" : "NO");
	}
	return 0;
}