class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>st;

        int i = 0, j = 0, maxsum = 0, temp = 0;

        while(j < nums.size()) {
            if(st.find(nums[j]) == st.end()) {
                st.insert(nums[j]);
                temp += nums[j];
                j++;
            }else {
                maxsum = max(maxsum, temp);
                while(nums[i]!=nums[j]) {
                    st.erase(nums[i]);
                    temp-=nums[i];
                    i++;
                }
                temp -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            maxsum = max(maxsum, temp);
        }
        return maxsum;
    }
};