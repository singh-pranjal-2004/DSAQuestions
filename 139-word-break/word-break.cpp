class Solution {
public:
    int t[301];

    bool solver(string& s, unordered_set<string>& st, int start) {
        if(start == s.length()) {
            return true;
        }

        if(t[start] != -1)
            return t[start];

        for(int i = start; i < s.length(); i++) {
            string temp = s.substr(start, i-start+1);

            if(st.find(temp) != st.end() && solver(s, st, i+1)) {
                return t[start] = true;
            }
        }

        return t[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memset(t, -1, sizeof(t));
        unordered_set<string>st(begin(wordDict),end(wordDict));
        return solver(s, st, 0);
    }
};