class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end()); // STL for next_permutation

        int n = nums.size();
        int index = -1, mini = nums[n-1], miniIndex = n-1;
        for(index = n-2; index >= 0; index--){
            if(nums[index] < nums[index+1]){
                break;
            }
        }

        cout<<index;

        if(index == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = n-1; i > index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }

        reverse(nums.begin()+index+1, nums.end());
    }
};