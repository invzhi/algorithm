#include <stdio.h>

#define N 101

// 1234567890987654321123456789 -> yi san wu

int main(int argc, char const *argv[])
{
	char n[N];
	scanf("%s", n);

	int sum = 0;
	for (int i = 0; n[i] != '\0'; i++) {
		sum += n[i] - '0';
	}

	char s[4]; // max: 900
	sprintf(s, "%d", sum);
	for (int i = 0; s[i] != '\0'; i++) {
		char* pinyin;
		switch (s[i]) {
			case '0':
				pinyin = "ling";
				break;
			case '1':
				pinyin = "yi";
				break;
			case '2':
				pinyin = "er";
				break;
			case '3':
				pinyin = "san";
				break;
			case '4':
				pinyin = "si";
				break;
			case '5':
				pinyin = "wu";
				break;
			case '6':
				pinyin = "liu";
				break;
			case '7':
				pinyin = "qi";
				break;
			case '8':
				pinyin = "ba";
				break;
			case '9':
				pinyin = "jiu";
				break;
		}
		printf(i ? " %s" : "%s", pinyin);
	}
	return 0;
}
