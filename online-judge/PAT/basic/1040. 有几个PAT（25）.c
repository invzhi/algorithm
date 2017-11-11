#include <stdio.h>

#define LIMIT 1000000007

int main(int argc, char const *argv[])
{
	char c;
	int p = 0, pa = 0, pat = 0;
	while ((c = getchar()) != '\n' && c != EOF) {
		switch (c) {
			case 'P':
				p++;
				break;
			case 'A':
				pa = (pa + p) % LIMIT;
				break;
			case 'T':
				pat = (pat + pa) % LIMIT;
				break;
		}
	}
	printf("%d", pat);
	return 0;
}
