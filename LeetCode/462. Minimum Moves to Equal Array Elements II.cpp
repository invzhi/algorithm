class Solution {
public:
	int minMoves2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int cnt = 0;
		int n = nums.size();
		for (int i = 0; i < n / 2; i++) {
			cnt += nums[n - 1 - i] - nums[i];
		}
		return cnt;
	}
};