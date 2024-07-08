class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, mini = prices[0];
        for(int i = 1; i < prices.size(); i++){
            mini = min(mini, prices[i-1]);
            ans = max(ans, prices[i]-mini);
        }
        return ans;
    }
};