class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size(), xoredXor = nums[0], maxXor = pow(2, maximumBit)-1;
        vector<int> ans(n);
        
        for(int i = 1; i < n; i++) xoredXor ^= nums[i];

        for(int i = 0; i < n; i++){
            ans[i] = xoredXor ^ maxXor;
            xoredXor ^= nums[n-1-i];
        }
        return ans;
    }
};