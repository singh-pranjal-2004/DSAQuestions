class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev1 = nums[0];
        
        for(int i = 2; i <= n; i++) {
            int take = nums[i-1] + prev2;
            int notTake = prev1;

            prev2 = prev1;
            prev1 = max(take, notTake);
        }

        return prev1;
    }
};