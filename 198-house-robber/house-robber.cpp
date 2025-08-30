class Solution {
public:
    int solver(vector<int>& nums, vector<int>& dp, int n, int i) {
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int take = nums[i] + solver(nums, dp, n, i+2);
        int notTake = solver(nums, dp, n, i+1);

        return dp[i] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return solver(nums, dp, n, 0);
    }
};