class Solution {
public:
    int solver(vector<int>& nums, int start, int end){
        int prev1 = nums[start];
        int prev2 = 0;

        for(int i = start+1; i <= end; i++){
            int take = nums[i] + (i-2 >= start ? prev2 : 0);
            int notTake = prev1;

            prev2 = prev1;
            prev1 = max(take, notTake);
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int ignoreFirst = solver(nums, 1, n-1);
        int ignoreLast = solver(nums, 0, n-2);

        return max(ignoreFirst, ignoreLast);
    }
};