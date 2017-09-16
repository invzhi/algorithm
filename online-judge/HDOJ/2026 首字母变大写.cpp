#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	char ch;
	bool isSpace = true;
	while ((ch = getchar()) != EOF) {
		if (isSpace) {
			isSpace = false;
			cout << (char)toupper(ch);
		} else if (ch == ' ' || ch == '\n') {
			isSpace = true;
			cout << ch;
		} else {
			cout << ch;
		}
	}
	return 0;
}