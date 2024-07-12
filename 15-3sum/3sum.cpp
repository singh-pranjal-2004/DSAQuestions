class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        for(int i = 0; i < n; i++){

            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1, k = n-1;
            while(j < k){
                int a = nums[i], b = nums[j], c = nums[k];
                int sum = a + b + c;
                if(sum == 0){
                    ans.push_back({a, b, c});
                    while(j < k && nums[j] == b) j++;
                    while(j < k && nums[k] == c) k--;
                }else if(sum > 0){
                    k--;
                }else if(sum < 0){
                    j++;
                }
            }
        }

        return ans;        
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();