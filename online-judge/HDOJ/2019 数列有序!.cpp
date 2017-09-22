#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	int num;
	while (cin >> n >> m && n) {
		while (n--) {
			cin >> num;
			if (m < num) {
				cout << m;
				m = num;
			}
			else cout << num;
			cout << ' ';
		}
		cout << m << endl;
	}
	return 0;
}
