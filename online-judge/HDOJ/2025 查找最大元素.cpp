#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>

#define MAXN 100 + 5

using namespace std;

char str[MAXN];

int main() {
	while (fgets(str, MAXN, stdin) && str[0]) {
		int max = str[0];
		int length = strlen(str);
		if (str[length - 1] == '\n') length--;
		for (int i = 1; i < length; i++) {
			if (str[i] > max) max = str[i];
		}
		for (int i = 0; i < length; i++) {
			cout << str[i] << (str[i] == max ? "(max)" : "");
		}
		cout << endl;
	}
	return 0;
}
