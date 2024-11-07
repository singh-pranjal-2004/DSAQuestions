class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] >= nums[i]){
                count++;
            }

            if(i>1 && nums[i-2] >= nums[i] && i+1 < n && nums[i-1] >= nums[i+1]) return false;

            if(count > 1) return false;
        }

        return true;
    }
};