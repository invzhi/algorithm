#include <iostream>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	int x, y;
	int n;
	while (cin >> x >> y && x != y) {
		bool ok = true;
		while (x <= y) {
			n = x * x + x + 41;
			if (!isPrime(n)) {
				ok = false;
				break;
			}
			x++;
		}
		cout << (ok ? "OK" : "Sorry") << endl;
	}
	return 0;
}