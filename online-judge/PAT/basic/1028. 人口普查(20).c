#include <stdio.h>
#include <string.h>

int isvaild(char date[]) { // 1814/09/06 ~ 2014/09/06
	return strcmp(date, "1814/09/06") >= 0 && strcmp(date, "2014/09/06") <= 0;
}

int main(int argc, char const *argv[])
{
	int n; // 0 < n <= 100000
	scanf("%d", &n);

	char name[6], date[11];
	char name_max[6], date_max[11] = "0000/00/00";
	char name_min[6], date_min[11] = "9999/99/99";

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s %s", name, date);
		if (isvaild(date)) {
			if (strcmp(date, date_max) > 0) {
				strcpy(name_max, name);
				strcpy(date_max, date);
			}
			if (strcmp(date, date_min) < 0) {
				strcpy(name_min, name);
				strcpy(date_min, date);
			}
			cnt++;
		}
	}

	if (cnt > 0) {
		printf("%d %s %s", cnt, name_min, name_max); // old, young
	} else {
		printf("0");
	}
	return 0;
}
