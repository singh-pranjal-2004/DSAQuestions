class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        double total = 0;
        int n = customers.size();

        total += customers[0][0];
        for(int i = 0; i < n; i++){
            if(total < customers[i][0]){
                total = customers[i][0];
            }
            total += customers[i][1];

            ans = ans + (total - customers[i][0]);
        }

        return ans/n;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();