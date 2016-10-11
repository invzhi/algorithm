/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void get(int i, int j, int n, char* s, char** ans, int* size) {
	if (i == n && j == n) {
		s[i + j] = 0;
		ans[(*size)] = (char*) malloc(sizeof(char) * (n + n + 1));
		strcpy(ans[(*size)++], s);
		return;
	}
	if (i < n) {
		s[i + j] = '(';
		get(i + 1, j, n, s, ans, size);
	}
	if (j < n && j < i) {
		s[i + j] = ')';
		get(i, j + 1, n, s, ans, size);
	}
}

char** generateParenthesis(int n, int* returnSize) {
	char** ans = (char**) malloc(sizeof(char*) * 10000);
	char* parenthesis = (char*) malloc(sizeof(n + n + 1));
	*returnSize = 0;
	get(0, 0, n, parenthesis, ans, returnSize);
	return ans;
}