class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = INT_MIN;
        for(auto i: nums){
            maxElement = max(maxElement, i);
        }

        int maxLength = 0, length = 0;
        for(int i = 0; i < nums.size(); i++){
            if(maxElement == nums[i]){
                length++;
            }else{
                length = 0;
            }
            maxLength = max(maxLength, length);
        }

        return maxLength;
    }
};