#include <stdio.h>
#include <ctype.h>

#define N 61

int isday(char c) {
	return c >= 'A' && c <= 'G';
}

int ishour(char c) {
	return (c >= 'A' && c <= 'N') || isdigit(c);
}

int main(int argc, char const *argv[])
{
	char s[4][N];
	for (int i = 0; i < 4; i++) {
		scanf("%s", s[i]);
	}

	char* week[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	int day, hour, minute;

	int i;
	for (i = 0; s[0][i] && s[1][i]; i++) {
		char c = s[0][i];
		if (c == s[1][i] && isday(c)) {
			day = c - 'A';
			break;
		}
	}
	for (i = i + 1; s[0][i] && s[1][i]; i++) {
		char c = s[0][i];
		if (c == s[1][i] && ishour(c)) {
			if (isdigit(c)) {
				hour = c - '0';
			} else {
				hour = c - 'A' + 10;
			}
			break;
		}
	}

	for (int i = 0; s[2][i] && s[3][i]; i++) {
		if (s[2][i] == s[3][i] && isalpha(s[2][i])) {
			minute = i;
			break;
		}
	}

	printf("%s %02d:%02d", week[day], hour, minute);
	return 0;
}
