#include <stdio.h>
#include <string.h>

#define N 82

int main(int argc, char const *argv[])
{
	char s[N] = "";
	fgets(s, N, stdin);
	int l = strlen(s);
	if (s[l-1] == '\n') {
		s[l-1] = '\0';
	}

	for (int i = l - 2; i > 0; i--) {
		if (s[i] == ' ') {
			s[i] = '\0';
			printf("%s ", s+i+1);
		}
	}
	printf("%s", s);
	return 0;
}
