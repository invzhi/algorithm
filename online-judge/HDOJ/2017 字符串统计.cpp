#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	char ch;
	cin >> n;
	getchar();
	while (n--) {
		int c = 0;
		while ((ch = getchar()) != '\n' && ch != EOF) {
			if (ch >= '0' && ch <= '9') c++;
		}
		cout << c << endl;
	}
	return 0;
}
