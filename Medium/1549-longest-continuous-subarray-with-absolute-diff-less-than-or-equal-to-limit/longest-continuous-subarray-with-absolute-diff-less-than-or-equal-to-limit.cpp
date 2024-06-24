class Solution {
public:
    typedef pair<int, int> P;
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        priority_queue<P, vector<P>, greater<P>> minHeap;
        priority_queue<P, vector<P>> maxHeap;

        int i = 0, j = 0, maxi = 0;
        while(j<n){
            minHeap.push({nums[j], j});
            maxHeap.push({nums[j], j});

            while(maxHeap.top().first - minHeap.top().first > limit){
                i = min(maxHeap.top().second, minHeap.top().second) + 1;

                while(maxHeap.top().second < i){
                    maxHeap.pop();
                }
                while(minHeap.top().second < i){
                    minHeap.pop();
                }
            }
            maxi = max(maxi, j-i+1);
            j++;
        }

        return maxi;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();