#include <stdio.h>
#include <string.h>

#define N 12

typedef struct {
	int score;
	int wrong;
	char answer[N];
} question;

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);

	question qs[m];
	for (int i = 0; i < m; i++) {
		qs[i].wrong = 0;
		scanf("%d %*d %[^\n]", &qs[i].score, &qs[i].answer);
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		int score = 0;
		for (int j = 0; j < m; j++) {
			char answer[N];
			scanf(" (%[^)])", answer);
			if (strcmp(answer, qs[j].answer) == 0) {
				score += qs[j].score;
			} else {
				qs[j].wrong++;
				if (qs[j].wrong > max) {
					max = qs[j].wrong;
				}
			}
		}
		printf("%d\n", score);
	}

	if (max == 0) {
		printf("Too simple");
	} else {
		printf("%d", max);
		for (int i = 0; i < m; i++) {
			if (max == qs[i].wrong) {
				printf(" %d", i+1);
			}
		}
	}

	return 0;
}
