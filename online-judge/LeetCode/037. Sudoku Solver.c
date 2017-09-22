bool row[9][9], col[9][9], block[9][9];

bool DFS(char** board, int i, int j) {
	if (i == 9) return true;
	if (j == 9) return DFS(board, i + 1, 0);
	if (board[i][j] != '.') return DFS(board, i, j + 1);
	for (int k = 0; k < 9; k++) {
		if (!row[i][k] && !col[j][k] && !block[i / 3 * 3 + j / 3][k]) {
			row[i][k] = col[j][k] = block[i / 3 * 3 + j / 3][k] = true;
			board[i][j] = k + '1';
			if (DFS(board, i, j + 1)) return true;
			board[i][j] = '.';
			row[i][k] = col[j][k] = block[i / 3 * 3 + j / 3][k] = false;
		}
	}
	return false;
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
	int i, j, c;
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(block, 0, sizeof(block));
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (board[i][j] != '.') {
				c = board[i][j] - '1';
				row[i][c] = col[j][c] = block[i / 3 * 3 + j / 3][c] = true;
			}
		}
	}
	DFS(board, 0, 0);
}
