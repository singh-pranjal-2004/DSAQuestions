class Solution {
public:
    bool checker(string str) {
        int i = 0, j = str.length()-1;
        while(i <= j) {
            if(str[i]!=str[j])
                return false;

            i++;
            j--;                
        }
        return true;
    }

    void solver(vector<vector<string>>& ans, vector<string>& strVec, string s, int n, int i) {
        if(i >= n) {
            ans.push_back(strVec);
            return;
        }

        for(int j = i; j < n; j++) {
            string temp = s.substr(i, j - i + 1);

            if(checker(temp)) {
                strVec.push_back(temp);
                solver(ans, strVec, s, n, j+1);
                strVec.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> str;

        solver(ans, str, s, s.length(), 0);

        return ans;
    }
};