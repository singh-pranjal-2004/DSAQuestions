class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int e = 0, o = 0;
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 0) {
                e++;
            }else o++;
        }

        while(e > 0) {
            ans.push_back(0);
            e--;
        }

        while(o > 0) {
            ans.push_back(1);
            o--;
        }

        return ans;
    }
};