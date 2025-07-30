class Solution {
public:
    void solver(unordered_map<string, string>& mp, vector<string>& ans, string temp, string digits, int n, int ind) {
        if(ind >= n){
            ans.push_back(temp);
            return;
        }

        string mapping = mp[string(1, digits[ind])];
        for(int i = 0; i < mapping.length(); i++) {
            temp.push_back(mapping[i]);
            solver(mp, ans, temp, digits, n, ind+1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.length();
        if(n==0) return ans;

        unordered_map<string, string> mp = {{"2", "abc"}, {"3", "def"}, {"4", "ghi"}, {"5", "jkl"}, {"6", "mno"}, {"7", "pqrs"}, {"8", "tuv"}, {"9", "wxyz"}};

        solver(mp, ans, "", digits, n, 0);

        return ans;
    }
};