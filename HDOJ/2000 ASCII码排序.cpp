#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
	char s[1000];
	while (scanf("%s", s) == 1) {
		int length = strlen(s);
		sort(s, s + length);
		int i;
		for (i = 0; i < length; i++) {
			cout << s[i];
			if (i != length - 1) cout << ' ';
		}
		cout << endl;
	}
	return 0;
}