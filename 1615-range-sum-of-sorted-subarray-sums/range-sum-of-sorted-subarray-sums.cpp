class Solution {
public:
    typedef pair<int, int> P;
    int m = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<P, vector<P>, greater<P>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        int result = 0;

        for (int count = 1; count <= right; count++) {
            auto p = pq.top();
            pq.pop();

            int sum = p.first;
            int idx = p.second;

            if (count >= left) {
                result = (result + sum) % m;
            }

            int newIdx = idx + 1;
            P new_pair;
            if (newIdx < n) {
                new_pair.first = sum + nums[newIdx];
                new_pair.second = newIdx;
                pq.push(new_pair);
            }
        }

        return result;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();