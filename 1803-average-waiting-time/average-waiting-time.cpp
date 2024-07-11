class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        double total = 0;
        int n = customers.size();

        total += customers[0][0];

        for(auto v: customers){
            int arrivalTime = v[0], cookingTime = v[1];
            if(total < arrivalTime) total = arrivalTime;

            total += cookingTime;

            ans = ans + (total - arrivalTime);
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