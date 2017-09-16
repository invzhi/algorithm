#include <cstdio>
#include <cmath>

int main() {
	int score;
	while (scanf("%d", &score) == 1) {
		if (score >= 90 && score <= 100) puts("A");
		else if (score >= 80 && score <= 89) puts("B");
		else if (score >= 70 && score <= 79) puts("C");
		else if (score >= 60 && score <= 69) puts("D");
		else if (score >= 0 && score <= 59) puts("E");
		else puts("Score is error!");
	}
	return 0;
}