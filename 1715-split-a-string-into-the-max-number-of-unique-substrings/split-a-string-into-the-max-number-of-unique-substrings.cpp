class Solution {
public:
    void solver(unordered_set<string>& ust, string& s, int idx, int currCount, int &maxCount){
        if(idx >= s.length()){
            maxCount = max(currCount, maxCount);
            return;
        }

        for(int j = idx; j < s.length(); j++){
            string sub = s.substr(idx, j-idx+1);
            if(ust.find(sub) == ust.end()){
                ust.insert(sub);
                solver(ust, s, j + 1, currCount+1, maxCount);
                ust.erase(sub);
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string>ust;
        int currCount = 0, maxCount = 0, idx = 0;

        solver(ust, s, idx, currCount, maxCount);

        return maxCount;
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();