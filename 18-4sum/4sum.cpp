class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int n = nums.size();
        for(int i = 0; i < n; i++){

            if(i > 0 && nums[i-1] == nums[i]) continue;

            for(int j = i + 1; j < n; j++){
                if(j > i+1 && nums[j-1] == nums[j]) continue;
                int k = j + 1;
                int l = n - 1;

                while(k < l){
                    int a = nums[i], b = nums[j], c = nums[k], d = nums[l];
                    long long sum = a + b;
                    sum += c;
                    sum += d;

                    if(sum < target) k++;
                    else if(sum > target) l--;
                    else{
                        ans.push_back({a, b, c, d});

                        while(k < l && nums[k] == c) k++;
                        while(k < l && nums[l] == d) l--;
                    }
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