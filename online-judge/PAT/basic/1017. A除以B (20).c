#include <stdio.h>

#define N 1001

int main(int argc, char const *argv[])
{
	char a[N];
	int b;
	scanf("%s %d", a, &b);

	char q[N];
	int r = 0;

	int i;
	for (i = 0; a[i] != '\0'; i++) {
		r = r*10 + (a[i] - '0');
		q[i] = r/b + '0';
		r %= b;
	}
	q[i] = '\0';

	int zero = 0;
	while (q[zero] == '0') {
		if (q[zero+1] == '\0') { // q == 0
			break;
		} else {
			zero++;
		}
	}
	printf("%s %d", q+zero, r);
	return 0;
}
