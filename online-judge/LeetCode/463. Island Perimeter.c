int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
	int i, j;
	int cnt = 0;
	for (i = 0; i < gridRowSize; i++) {
		for (j = 0; j < gridColSize; j++) {
			if (i == 0 || j == 0) {
				if (grid[i][j]) {
					cnt += 4;
					if (i && grid[i - 1][j] || j && grid[i][j - 1]) cnt -= 2;
				}
			} else if (grid[i][j]) {
				cnt += 4;
				if (grid[i - 1][j]) cnt -= 2;
				if (grid[i][j - 1]) cnt -= 2;
			}
		}
	}
	return cnt;
}
