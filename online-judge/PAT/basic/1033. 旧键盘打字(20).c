#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	char isbroken[128];
	memset(isbroken, 0, sizeof(isbroken));

	char c;
	while ((c = getchar()) != '\n') {
		if (c == '+' && isbroken[c] == 0) {
			for (char upper = 'A'; upper <= 'Z'; upper++) {
				isbroken[upper] = 1;
			}
		} else if (isupper(c)) {
			isbroken[tolower(c)] = 1;
		}
		isbroken[c] = 1;
	}

	while ((c = getchar()) != '\n' && c != EOF) {
		if (isbroken[c] == 0) {
			putchar(c);
		}
	}

	return 0;
}
