class Solution {
public:
	int nMax(vector<int>& nums, int n) {
		set<int> topN;
		for(int num: nums) {
			topN.insert(num);
			if (topN.size() > n) topN.erase(topN.begin());
		}
		return topN.size() < n ? *(topN.rbegin()) : *(topN.begin());
	}
	int thirdMax(vector<int>& nums) {
		return nMax(nums, 3);
	}
};
