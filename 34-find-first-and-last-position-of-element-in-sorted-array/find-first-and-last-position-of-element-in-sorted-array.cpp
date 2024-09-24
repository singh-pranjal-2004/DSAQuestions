class Solution {
public:
    int firstBinary(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                ans = mid;
                high = mid - 1;
            }else if(target > nums[mid]){
                low = mid + 1;
            }else high = mid - 1;
        }
        return ans;
    }

    int lastBinary(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                ans = mid;
                low = mid + 1;
            }else if(target > nums[mid]){
                low = mid + 1;
            }else high = mid - 1;
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstBinary(nums, target);
        int last = lastBinary(nums, target);

        return {first, last};
    }
};