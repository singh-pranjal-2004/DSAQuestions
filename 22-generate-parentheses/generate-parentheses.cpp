class Solution {
public:
    void solver(vector<string>& ans, int n, string str, int open, int close) {
        if(open == n && close == n) {
            ans.push_back(str);
            return;
        }

        if(open < n)
            solver(ans, n, str+"(", open+1, close);
        
        if(close < open) 
            solver(ans, n, str+")", open, close+1);

    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;

        solver(ans, n, "(", 1, 0);

        return ans;
    }
};