class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int>mp;
        for(int &num: nums1){
            mp[num]++;
        }

        vector<int>ans;
        for(int i = 0;i<nums2.size();i++){
            int num = nums2[i];
            if(mp[num] > 0){
                mp[num]--;
                ans.push_back(num);
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