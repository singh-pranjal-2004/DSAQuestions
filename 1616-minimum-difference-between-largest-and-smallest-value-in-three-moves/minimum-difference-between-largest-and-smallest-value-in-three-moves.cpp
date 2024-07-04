class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();

        if(n<=4){
            return 0;
        }

        partial_sort(begin(nums), begin(nums)+4, end(nums)); // O(n*log(4)) -> O(n)

        nth_element(begin(nums) + 4, begin(nums) + (n-4), end(nums)); // O(n)

        sort(begin(nums)+(n-4), end(nums)); // O(4log(4)) -> O(1)

        int ans = INT_MAX;
        for(int i = 0; i < 4; i++){
            ans = min(ans, nums[n-1-3+i] - nums[i]);
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