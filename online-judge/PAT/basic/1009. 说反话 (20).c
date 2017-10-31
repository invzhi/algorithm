#include <stdio.h>
#include <string.h>

#define N 81

int main(int argc, char const *argv[])
{
	char s[N] = "";
	gets(s); // fgets(s, N, stdin);

	for (int i = strlen(s) - 2; i > 0; i--) {
		if (s[i] == ' ') {
			s[i] = '\0';
			printf("%s ", s+i+1);
		}
	}
	printf("%s", s);
	return 0;
}
