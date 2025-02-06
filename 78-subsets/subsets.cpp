class Solution {
public:
    void solver(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums, int i) {
        if(i >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        // exclude
        solver(ans, temp, nums, i+1);

        //include
        temp.push_back(nums[i]);
        solver(ans, temp, nums, i+1);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;

        solver(ans, temp, nums, 0);

        return ans;
    }
};