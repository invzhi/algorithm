#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int money[] = {100, 50, 10, 5, 2, 1};

int main() {
	int n;
	while (cin >> n && n) {
		int p = 0;
		int earn;
		for (int i = 0; i < n; i++) {
			cin >> earn;
			for (int j = 0; j < 6; j++) {
				while (earn >= money[j]) {
					earn -= money[j];
					p++;
				}
			}
		}
		cout << p << endl;
	}
	return 0;
}
