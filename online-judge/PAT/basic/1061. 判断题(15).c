#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);

	int full[m];
	for (int i = 0; i < m; i++) {
		scanf("%d", &full[i]);
	}

	int result[m];
	for (int i = 0; i < m; i++) {
		scanf("%d", &result[i]);
	}

	for (int i = 0; i < n; i++) {
		int score = 0;
		for (int j = 0; j < m; j++) {
			int answer;
			scanf("%d", &answer);
			if (answer == result[j]) {
				score += full[j];
			}
		}
		printf("%d\n", score);
	}

	return 0;
}
