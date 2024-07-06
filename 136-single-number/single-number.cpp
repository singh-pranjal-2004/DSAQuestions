class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1 = 0;
        for(auto i: nums) xor1 ^= i;
        return xor1;
    }
};