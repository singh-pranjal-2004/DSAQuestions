class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = 0, mini = 0, currMax = 0, currMin = 0;

        for(auto i: nums) {
            currMax = max(i, currMax + i);
            maxi = max(maxi, currMax);

            currMin = min(i, currMin + i);
            mini = min(mini, currMin);
        }

        return max(abs(maxi), abs(mini));
    }
};