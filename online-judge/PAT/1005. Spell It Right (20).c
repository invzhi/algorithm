#include <stdio.h>
#include <string.h>

// Sample Input:
// 12345 (N <= 10^100)
// Sample Output:
// one five

#define N 101

int main(int argc, char const *argv[])
{
	char* num[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	
	char n[N], res[N];
	int sum = 0;

	scanf("%s", n);
	int len = strlen(n);
	for (int i = 0; i < len; i++) {
		sum += n[i] - '0';
	}

	len = sprintf(res, "%d", sum);
	printf("%s", num[res[0] - '0']);
	for (int i = 1; i < len; i++) {
		int index = res[i] - '0';
		printf(" %s", num[index]);
	}
	return 0;
}
