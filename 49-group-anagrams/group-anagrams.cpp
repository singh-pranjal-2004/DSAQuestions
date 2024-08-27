class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;

        map<string, vector<string>>mp;
        for(auto i: strs){
            string s = i;
            sort(begin(s), end(s));
            mp[s].push_back(i);
        }

        for(auto i: mp){
            ans.push_back(i.second);
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