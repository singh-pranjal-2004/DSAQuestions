class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum+=nums[i];
            ans = max(ans, sum);
            if(sum < 0){ // Kadane's Algorithm - Make sum 0 if the sum is a negative number
                sum = 0;
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