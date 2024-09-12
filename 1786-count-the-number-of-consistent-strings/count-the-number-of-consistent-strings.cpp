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
