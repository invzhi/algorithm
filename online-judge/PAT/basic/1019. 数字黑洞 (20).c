#include <stdio.h>
#include <stdlib.h>

int cmp_a(const void* a, const void* b) {
	return *(char*)b - *(char*)a;
}

int cmp_b(const void* a, const void* b) {
	return *(char*)a - *(char*)b;
}

int geta(int num) {
	char a[5];
	sprintf(a, "%04d", num);
	qsort(a, 4, sizeof(char), cmp_a);
	return atoi(a);
}

int getb(int num) {
	char b[5];
	sprintf(b, "%04d", num);
	qsort(b, 4, sizeof(char), cmp_b);
	return atoi(b);
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	do {
		int a = geta(n);
		int b = getb(n);
		n = a - b;
		printf("%04d - %04d = %04d\n", a, b, n);
	} while (n != 6174 && n != 0);

	return 0;
}
