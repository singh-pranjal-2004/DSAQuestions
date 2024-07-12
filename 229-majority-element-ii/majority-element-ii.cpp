class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int>mp;
        
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        int threshold = nums.size() / 3;

        for(auto it: mp){
            int number = it.first;
            int count = it.second;

            if(count > threshold) ans.push_back(number);
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