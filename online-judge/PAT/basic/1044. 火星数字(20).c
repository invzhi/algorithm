#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* low[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char* high[] = {"   ", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void print_mars(int num) {
	int h = num / 13;
	int l = num % 13;
	if (h > 0 && l > 0) {
		printf("%s %s\n", high[h], low[l]);
	} else if (h > 0) { // l == 0
		puts(high[h]);
	} else { // h == 0
		puts(low[l]);
	}
}

void print_earth(char h[], char l[]) {
	if (l[0] == '\0') { // only one mars
		l = h;
	}
	int earth = 0;
	for (int i = 1; i < 13; i++) {
		if (strcmp(high[i], h) == 0) {
			earth = 13 * i;
			break;
		}
	}
	if (earth == 0 || h != l) { // only h: not find yet; h, l: must continue
		for (int i = 0; i < 13; i++) {
			if (strcmp(low[i], l) == 0) {
				earth += i;
				break;
			}
		}
	}
	printf("%d\n", earth);
}

int main(int argc, char const *argv[])
{
	int n; // 0 < n < 100
	scanf("%d ", &n);

	char num[10];
	for (int i = 0; i < n; i++) {
		fgets(num, 10, stdin);
		if (isdigit(num[0])) {
			int earth;
			sscanf(num, "%d", &earth);
			print_mars(earth);
		} else {
			char h[4], l[5] = "";
			sscanf(num, "%s", h);
			if (num[3] == ' ') {
				sscanf(num+4, "%s", l);
			}
			print_earth(h, l);
		}
	}

	return 0;
}
