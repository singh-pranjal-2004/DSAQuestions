class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes = 0, ans = INT_MAX;
        int n = nums.size();
        for(auto i: nums){
            if(i) totalOnes++;
        }

        int currentOnes = 0;
        for(int j = 0; j < totalOnes; j++){
            currentOnes += nums[j];
        }

        for(int i = 0; i < n; i++){
            ans = min(ans, totalOnes - currentOnes);
            currentOnes -= nums[i];
            currentOnes += nums[(i+totalOnes) % n];
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