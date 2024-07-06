class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1 = 0;
        for(auto i: nums) xor1 ^= i;
        return xor1;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();