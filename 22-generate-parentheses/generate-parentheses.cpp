class Solution {
public:
    void solver(vector<string>& ans, string str, int open, int close, int n){
        if(open == n && close == n){
            ans.push_back(str);
            return;
        }

        if(open == n){
            str += ')';
            solver(ans, str, open, close+1, n);
            return;
        }

        solver(ans, str + '(', open + 1, close, n);
        if(open > close) solver(ans, str + ')', open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        if(n == 0) return ans;

        solver(ans, "(", 1, 0, n);
        
        return ans;
    }
};