class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto i: nums) pq.push(i);

        long long ans = 0;

        while(k--){
            double tp = pq.top();
            pq.pop();

            ans += tp;

            tp /= 3.00;

            pq.push(ceil(tp));
        }

        return ans;
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();