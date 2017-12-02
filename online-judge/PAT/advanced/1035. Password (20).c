#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
	char username[n][11], password[n][11];
	int m = 0;

	for (int i = 0; i < n; i++) {
		scanf("%s %s", username[m], password[m]);

		int isModified = 0;
		for (int j = 0; password[m][j] != '\0'; j++) {
			switch (password[m][j]) {
			case '1':
				password[m][j] = '@';
				isModified = 1;
				break;
			case '0':
				password[m][j] = '%';
				isModified = 1;
				break;
			case 'l':
				password[m][j] = 'L';
				isModified = 1;
				break;
			case 'O':
				password[m][j] = 'o';
				isModified = 1;
				break;
			}
		}
		if (isModified) {
			m++;
		}
	}

	if (m == 0) {
		printf("There %s %d account%s and no account is modified", n > 1 ? "are" : "is", n, n > 1 ? "s" : "");
	} else {
		printf("%d", m);
		for (int i = 0; i < m; i++) {
			printf("\n%s %s", username[i], password[i]);
		}
	}

	return 0;
}
