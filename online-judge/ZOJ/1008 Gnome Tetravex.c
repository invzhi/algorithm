#include <stdio.h>
#include <string.h>

int n, num, kind;
int square[25][4];
int numOfSquare[25];
int ans[25];

int DFS(int cur) {
	if (cur == num) return 1;
	int i;
	for (i = 0; i < kind; i++) {
		if (numOfSquare[i] == 0) continue;
		if (cur / n && square[ans[cur - n]][2] != square[i][0]) continue;
		if (cur % n && square[ans[cur - 1]][1] != square[i][3]) continue;
		ans[cur] = i;
		numOfSquare[i]--;
		if (DFS(cur + 1)) return 1;
		numOfSquare[i]++;
	}
	return 0;
}

int main() {
	int i, j, a, b, c, d, first = 1, k = 0;
	while (scanf("%d", &n) && n) {
		kind = 0;
		num = n * n;
		for (i = 0; i < num; i++) {
			scanf("%d%d%d%d", &a, &b, &c, &d);
			for (j = kind - 1; j >= 0; j--) {
				if (a == square[j][0] && b == square[j][1] && c == square[j][2] && d == square[j][3]) {
					numOfSquare[j]++;
					break;
				}
			}
			if (j == -1) {
				square[kind][0] = a;
				square[kind][1] = b;
				square[kind][2] = c;
				square[kind][3] = d;
				numOfSquare[kind] = 1;
				kind++;
			}
		}
		if (first) first = 0;
		else printf("\n");
		if (DFS(0)) printf("Game %d: Possible\n", ++k);
		else printf("Game %d: Impossible\n", ++k);
	}
	return 0;
}