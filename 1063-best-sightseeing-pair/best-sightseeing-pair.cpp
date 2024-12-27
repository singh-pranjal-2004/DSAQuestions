class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int maxAns = INT_MIN;
        int maxTillNow = values[0];
        for(int i = 1; i < n; i++){
            maxAns = max(maxAns, maxTillNow + values[i] - i);

            maxTillNow = max(maxTillNow, values[i]+i);
        }

        return maxAns;
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();