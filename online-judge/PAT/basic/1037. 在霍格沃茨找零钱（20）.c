#include <stdio.h>

int main(int argc, char const *argv[])
{
	int p, a;
	int galleon, sickle, knut;

	scanf("%d.%d.%d", &galleon, &sickle, &knut);
	p = (galleon*17 + sickle)*29 + knut;
	scanf("%d.%d.%d", &galleon, &sickle, &knut);
	a = (galleon*17 + sickle)*29 + knut;

	int res = a - p;
	if (res < 0) {
		res = -res;
		putchar('-');
	}
	printf("%d.%d.%d", res/29/17, res/29%17, res%29);

	return 0;
}
