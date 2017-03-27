#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int m, n;
	int score;
	int s, x, y;
	bool isIntMin;
	while (cin >> m >> n) {
		isIntMin = false;
		s = INT_MIN;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> score;
				if (score == INT_MIN) {
					isIntMin = true;
					cout << i + 1 << ' ' << j + 1 << ' ' << score << endl;
				} else if (abs(score) > abs(s)) {
					s = score;
					x = i + 1;
					y = j + 1;
				}
			}
		}
		if (!isIntMin) cout << x << ' ' << y << ' ' << s << endl;
	}
	return 0;
}