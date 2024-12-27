class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        vector<int>maxVal(n, INT_MIN);
        maxVal[0] = values[0];
        for(int i = 1; i < n; i++){
            maxVal[i] = max(maxVal[i-1], values[i]+i);
        }

        int maxAns = INT_MIN;
        for(int i = 1; i < n; i++){
            maxAns = max(maxAns, maxVal[i-1] + values[i] - i);
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