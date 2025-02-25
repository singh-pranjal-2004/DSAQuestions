class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;

        for(int i: nums) {
            mp[i]++;
        }

        priority_queue<pair<int, int>>pq;

        for(auto m: mp) {
            int f = m.second;
            int n = m.first;

            pq.push({f, n});
        }

        vector<int>ans;
        for(int i = 0; i < k; i++) {
            int t = pq.top().second;
            pq.pop();
            ans.push_back(t);
        }

        return ans;
    }
};