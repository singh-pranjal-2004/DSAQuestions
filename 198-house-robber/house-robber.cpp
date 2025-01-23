class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int curr = nums[0];
        int prev = 0;

        for(int i = 1; i < n; i++){
            int a = nums[i] + (i>=2 ? prev : 0);
            int b = curr;

            prev = curr;
            curr = max(a, b);
        }

        return curr;
    }
};