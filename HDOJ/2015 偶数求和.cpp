#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m) {
		bool first = true;
		int c = n/m;
		int avg = m + 1;
		for (int i = 0; i < c; i++) {
			if (first) {
				first = false;
				cout << avg;
			} else {
				cout << ' ' << avg;
			}
			avg += 2 * m;
		}
		int mod;
		if (mod = n%m) {
			int num = (m*c + 1) * 2;
			int sum = 0;
			for (int i = 0; i < mod; i++) {
				sum += num;
				num += 2;
			}
			cout << ' ' << sum/mod;
		}
		cout << endl;
	}
	return 0;
}