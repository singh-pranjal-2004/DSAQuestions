class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>subarr;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                subarr.push_back(sum);
            }
        }

        sort(begin(subarr), end(subarr));

        int ans = 0;
        const int mod = 1e9 + 7;
        while(left<=right){
            ans = (ans + subarr[left-1]) % mod;
            left++;
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