#include <iostream>
#include <string>

using namespace std;

bool standardString(string& s) {
	while (!s.empty() && s[0] == '0') s.erase(s.begin());
	if (s.empty()) s = "0";
	bool existDot = false;
	for (unsigned int i = 0; i < s.size(); i++) {
		if (s[i] == '.') {
			existDot = true;
			break;
		}
	}
	if (!existDot) return false;
	while (!s.empty() && s[s.size() - 1] == '0') s.erase(s.end() - 1);
	if (!s.empty() && s[s.size() - 1] == '.') s.erase(s.end() - 1);
	if (s.empty()) s = "0";
	return true;
}

int handleDot(string& s) {
	if (!standardString(s)) return 0;
	int suffix = 0;
	for (unsigned int i = 0, j = 0; i < s.size(); i++) {
		if (s[i] != '.') s[j++] = s[i];
		else suffix = s.size() - i - 1;
	}
	s.erase(s.end() - 1);
	return suffix;
}

string multStr(string a, string b) {
	if (a == "0" || b == "0") return "0";
	int ap = handleDot(a);
	int bp = handleDot(b);
	string ans(a.size() + b.size(), '0');
	for (int i = a.size() - 1; i >= 0; i--) {
		int last = 0;
		int ac = a[i] - '0';
		for (int j = b.size() - 1; j >= 0; j--) {
			int bc = b[j] - '0';
			int mult = ac * bc + last + (ans[i + j + 1] - '0');
			last = mult / 10;
			ans[i + j + 1] = mult % 10 + '0';
		}
		if (last) ans[i] += last;
	}
	if (ap || bp) ans.insert(ans.end() - ap - bp, '.');
	standardString(ans);
	return ans;
}

string strPow(string s, int n) {
	// if (s.empty() || s == "0") return "0";
	if (n == 0) return "1";
	if (n == 1) return s;
	string ans = "1";
	while (n) {
		if (n & 1) ans = multStr(ans, s);
		s = multStr(s, s);
		n >>= 1;
	}
	return ans;
}

int main() {
	string R;
	int n;
	while (cin >> R >> n) {
		standardString(R);
		cout << strPow(R, n) << endl;
	}
	return 0;
}