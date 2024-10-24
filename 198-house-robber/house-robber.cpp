class Solution {
public:
    int solver(vector<int>& nums, vector<int>& dp, int idx){
        if(idx == 0) return nums[0];

        if(idx < 0) return 0;

        if(dp[idx] != -1) return dp[idx];

        int take = nums[idx] + solver(nums, dp, idx-2);
        int notTake = 0 + solver(nums, dp, idx-1);

        return dp[idx] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);

        return solver(nums, dp, n-1);
    }
};