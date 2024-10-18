class Solution {
public:
    int solver(vector<int>& nums, int maxOr, int currOr, int idx){
        if(idx >= nums.size()){
            if(maxOr == currOr) return 1;
            return 0;
        }

        // take
        int take = solver(nums, maxOr, currOr | nums[idx], idx+1);

        // not take
        int notTake = solver(nums, maxOr, currOr, idx+1);

        return take + notTake;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(auto i: nums){
            maxOr |= i;
        }

        int currOr = 0, idx = 0;
        return solver(nums, maxOr, currOr, idx);
    }
};