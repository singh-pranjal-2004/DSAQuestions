class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        int n = nums.size();

        int mini = INT_MAX;
        int maxi = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= mini) { 
                mini = nums[i];
            } else if(nums[i] <= maxi) {
                maxi = nums[i];
            } else {
                return true;
            }
        }

        return false;

        return false;
        
    }
};