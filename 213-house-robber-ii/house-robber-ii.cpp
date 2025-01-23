class Solution {
public:
    int solver(vector<int>& nums, vector<int>& dp, int start, int end){
        dp[start] = nums[start];

        for(int i = start+1; i <= end; i++){
            int take = nums[i] + (i-2 >= start ? dp[i-2] : 0);
            int notTake = dp[i-1];

            dp[i] = max(take, notTake);
        }

        return dp[end];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int>dp1(n, 0);
        vector<int>dp2(n, 0);
        int ignoreFirst = solver(nums, dp1, 1, n-1);
        int ignoreLast = solver(nums, dp2, 0, n-2);

        return max(ignoreFirst, ignoreLast);
    }
};