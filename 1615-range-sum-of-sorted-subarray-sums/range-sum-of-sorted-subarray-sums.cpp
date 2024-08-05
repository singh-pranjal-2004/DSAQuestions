class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<int, vector<int>, greater<int>>pq;

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                pq.push(sum);
            }
        }

        int ans = 0;
        const int mod = 1e9 + 7;
        int s = pq.size();
        for(int i = 1; i <= s ; i++){
            if(i > right) break;
            if(i >= left && i <= right) ans = (ans + pq.top()) % mod;

            pq.pop();
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