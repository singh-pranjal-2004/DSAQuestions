class Solution {
public:
    void solver(string s, set<string>& st, int start, string& temp,
                vector<string>& result) {

        if (start == s.length()) {
            result.push_back(temp);
            return;
        }

        for (int end = start + 1; end <= s.length(); end++) {
            string substring = s.substr(start, end - start);

            if (st.find(substring) != st.end()) {
                string newStr =
                    (temp.empty() ? substring : temp + " " + substring);
                solver(s, st, end, newStr, result);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        vector<string> result;
        string temp = "";

        solver(s, st, 0, temp, result);

        return result;
    }
};