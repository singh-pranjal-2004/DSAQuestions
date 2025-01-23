class Solution {
public:
    int solver(vector<int>& nums, vector<int>& dp, int idx){
        if(idx == 0) return nums[0];

        if(idx < 0) return 0;

        if(dp[idx] != -1) return dp[idx];

        int a = nums[idx] + solver(nums, dp, idx-2);
        int b = solver(nums, dp, idx-1);

        return dp[idx] = max(a, b);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return solver(nums, dp, n-1);
    }
};