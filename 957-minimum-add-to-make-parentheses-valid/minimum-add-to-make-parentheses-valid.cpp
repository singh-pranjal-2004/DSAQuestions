class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        int ans = 0;
        for(auto ch: s){
            if(ch == ')') close++;
            else if(ch == '(') open++;

            if(close > open){
                ans++;
                open++;
            }
        }

        return ans + (open - close);
    }
};