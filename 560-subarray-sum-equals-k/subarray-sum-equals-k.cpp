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
            if(mp.find(rem) != mp.end()){
                count += mp[rem];
            }

            mp[sum]++;
        }

        return count;
    }
};