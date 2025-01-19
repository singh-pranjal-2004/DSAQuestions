class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int left, int right){
        if(left > right) return -1;
        int mid = (left + right) / 2;

        if(target == nums[mid]) return mid;
        else if(target > nums[mid]) return binarySearch(nums, target, mid+1, right);
        else return binarySearch(nums, target, left, mid-1);
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        int ans = binarySearch(nums, target, 0, n);
        return ans;
    }
};