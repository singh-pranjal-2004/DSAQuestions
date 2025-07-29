class Solution {
public:
    void solver(vector<vector<int>>& ans, vector<int> temp, vector<int>& nums, int ind, int n) {
        ans.push_back(temp);

        for(int i = ind; i < n; i++) {
            if(i != ind && nums[i] == nums[i-1])
                continue;
            
            temp.push_back(nums[i]);
            solver(ans, temp, nums, i+1, n);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        vector<int>temp;

        solver(ans, temp, nums, 0, nums.size());

        return ans;
    }
};