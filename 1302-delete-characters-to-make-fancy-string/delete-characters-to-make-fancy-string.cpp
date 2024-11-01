class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int c = 0;

        for(int i = 0; i < s.length(); i++){
            if(ans.length() != 0 && ans[ans.length()-1] == s[i]) c++;
            else c = 0;

            if(c<2) ans += s[i];
        }

        return ans;
    }
};