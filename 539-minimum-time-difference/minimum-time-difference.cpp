class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>mini;

        for(auto str: timePoints){
            string hr = str.substr(0,2);
            string mn = str.substr(3, 2);

            int iHr = stoi(hr);
            int iMn = stoi(mn);
            int totalMin = iHr * 60 + iMn;
            mini.push_back(totalMin);
        }

        sort(begin(mini), end(mini));
        int n = mini.size();
        int minDiff = INT_MAX;
        for(int i = 1; i < n; i++){
            minDiff = min(minDiff, mini[i]-mini[i-1]);
        }

        int firstLastByChance = mini[0] + 1440 - mini[n-1];
        int lastDiff = min(minDiff, firstLastByChance);

        return lastDiff;
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();