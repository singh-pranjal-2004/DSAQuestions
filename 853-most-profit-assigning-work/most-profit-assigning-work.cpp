class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = worker.size();
        sort(worker.begin(), worker.end());
        vector<pair<int, int>>nums;
        for(int i = 0;i<n;i++){
            nums.push_back({difficulty[i], profit[i]});
        }
        sort(nums.begin(), nums.end());

        int maxProfit = 0;
        int temp = 0;

        for(int i = 0, j = 0; i<n;i++){
            while(j<difficulty.size() && nums[j].first <= worker[i]){
                temp = max(temp, nums[j].second);
                j++;
            }

            maxProfit = maxProfit + temp;
        }
        return maxProfit;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();