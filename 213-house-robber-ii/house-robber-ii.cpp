class Solution {
public:
    int solver(vector<int>& nums, vector<int>& dp, int start, int end){
        if(end == start) return nums[start];

        if(end < start) return 0;

        if(dp[end] != -1) return dp[end];

        int take = nums[end] + solver(nums, dp, start, end-2);
        int notTake = solver(nums, dp, start, end-1);

        return dp[end] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int>dp1(n, -1);
        vector<int>dp2(n, -1);
        int ignoreFirst = solver(nums, dp1, 1, n-1);
        int ignoreLast = solver(nums, dp2, 0, n-2);

        return max(ignoreFirst, ignoreLast);
    }
};