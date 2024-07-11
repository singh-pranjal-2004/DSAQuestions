class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int>mp;
        int sum = 0;
        mp[sum]++;
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            int rem = sum - k;
            count += mp[rem];

            mp[sum]++;
        }

        return count;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();