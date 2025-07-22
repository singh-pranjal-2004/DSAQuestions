class Solution {
public:
    void solver(vector<string>& ans, int n, string temp, int open, int close) {
        if(close == n) {
            ans.push_back(temp);
            return;
        }

        if(open == n) {
            temp.push_back(')');
            solver(ans, n, temp, open, close+1);
            return;
        }

        temp.push_back('(');
        solver(ans, n, temp, open+1, close);
        temp.pop_back();

        if(open > close) {
            temp.push_back(')');
            solver(ans, n, temp, open, close+1);
            temp.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;

        solver(ans, n, temp, 0, 0);

        return ans;
    }
};