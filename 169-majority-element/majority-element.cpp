class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int count = 0, n = nums.size(), element;

        for(int i = 0;i<n;i++){
            if(count==0){
                count = 1;
                element = nums[i];
            }else if(nums[i]==element) count++;
            else count--;
        } 

        int eleCount = 0;
        for(int i = 0;i<n;i++){
            if(element == nums[i]) eleCount++;
        }

        if(eleCount > n/2) return element;

        return -1;
    }
};