#include <stdio.h>

// Sample Input:
// 12345 (N <= 10^100)
// Sample Output:
// one five

int main(int argc, char const *argv[])
{
	char* toword[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	
	int sum = 0;
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {
		sum += c - '0';
	}

	char res[4]; // max: 892
	sprintf(res, "%d", sum);

	printf("%s", toword[res[0]-'0']);
	for (int i = 1; res[i] != '\0'; i++) {
		printf(" %s", toword[res[i]-'0']);
	}

	return 0;
}
