#include <stdio.h>

#define N 10000

int main(int argc, char const *argv[])
{
	char a[N];
	int n;
	scanf("%[^E]E%d", a, &n); // a * 10^n

	if (a[0] == '-') {
		putchar('-');
	}
	if (n < 0) {
		printf("0.");
		while (++n < 0) {
			putchar('0');
		}
		putchar(a[1]);
		for (int i = 3; a[i] != '\0'; i++) {
			putchar(a[i]);
		}
	} else {
		putchar(a[1]);
		int i = 3;
		while (n--) {
			if (a[i] != '\0'){
				putchar(a[i++]);
			} else {
				putchar('0');
			}
		}
		if (a[i] != '\0') {
			putchar('.');
			while (a[i] != '\0') {
				putchar(a[i++]);
			}
		}
	}
	return 0;
}
