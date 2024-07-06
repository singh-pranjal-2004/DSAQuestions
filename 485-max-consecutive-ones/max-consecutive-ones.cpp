class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, ans = INT_MIN;
        for(auto i: nums){
            if(i==1) count++;
            else{
                ans = max(ans, count);
                count = 0;
            }
        }
        ans = max(ans, count);
        return ans;
    }
};