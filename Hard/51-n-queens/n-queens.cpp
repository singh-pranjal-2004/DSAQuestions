class Solution {
public:
    bool possible(int row, int col, vector<string> board, int n){
        int trow = row, tcol = col;

        // left
        while(tcol >= 0){
            if(board[trow][tcol]=='Q') return false;

            tcol--;
        }

        // up diagonal
        trow = row, tcol = col;
        while(tcol>=0 && trow>=0){
            if(board[trow][tcol]=='Q') return false;
            trow--;
            tcol--;
        }

        // down diagonal
        trow = row, tcol = col;
        while(tcol>=0 && trow<n){
            if(board[trow][tcol]=='Q') return false;

            trow++;
            tcol--;
        }

        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row = 0;row<n;row++){
            if(possible(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
       vector<string> board(n);
       string s(n, '.');
       for(int i = 0;i<n;i++){
        board[i] = s;
       } 

       solve(0, board, ans, n);

       return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();