class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int xr = 0;
        if(n1%2 == 1) for(auto i: nums2) xr ^= i;
        if(n2%2 == 1) for(auto i: nums1) xr ^= i;

        return xr;

    }
};