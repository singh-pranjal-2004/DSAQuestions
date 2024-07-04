class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.end()-k, nums.end());
        reverse(nums.begin(), nums.end()-k);
        reverse(nums.begin(), nums.end());
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();