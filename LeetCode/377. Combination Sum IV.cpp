class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		int dp[target + 1] = {1};
		for(int i = 1; i <= target; i++) {
			dp[i] = 0;
			for(int num: nums) {
				if(i >= num) dp[i] += dp[i - num];
			}
		}
		return dp[target];
	}
};