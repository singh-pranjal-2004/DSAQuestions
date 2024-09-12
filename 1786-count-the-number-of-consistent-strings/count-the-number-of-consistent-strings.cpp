class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>st;
        for(auto i: allowed){
            st.insert(i);
        }

        int count = 0;
        for(auto str: words){
            bool allow = true;
            for(auto ch: str){
                if(st.find(ch) == st.end()){
                    allow = false;
                    break;
                }
            }
            count += allow;
        }

        return count;
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();