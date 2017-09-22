class Solution {
public:
	string longestPalindrome(string s) {
		if (s.length() == 0) return "";
		string s2;
		addBoundaries(s, s2);
		int c = 0, r = 0;
		int maxc, maxp = 0;
		int p[s2.length()] = {0};
		for (int i = 1; i < s2.length(); i++) {
			p[i] = i > r ? 0 : min(p[2 * c - i], r - i);
			while (s2[i + p[i] + 1] == s2[i - p[i] - 1]) p[i]++;
			if (i + p[i] > r) {
				c = i;
				r = i + p[i];
			}
			if (p[i] > maxp) {
				maxc = i;
				maxp = p[i];
			}
		}
		s.clear();
		for (int i = maxc - maxp + 1; i < maxc + maxp; i += 2) {
			s += s2[i];
		}
		return s;
	}

	void addBoundaries(const string& s, string& s2) {
		s2 += '<';
		for (int i = 0; i < s.length(); i++) {
			s2 += '|';
			s2 += s[i];
		}
		s2 += "|>";
	}
};
