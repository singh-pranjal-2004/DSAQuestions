class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }

    bool solver(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char c = '1'; c <= '9'; c++) {
                        if(possible(board, i, j, c)){
                            board[i][j] = c;
                            if(solver(board)){
                                return true;
                            }else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool possible(vector<vector<char>>& board, int row, int col, char c){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == c || board[i][col] == c){
                return false;
            }

            if(board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c){
                return false;
            }
        }
        return true;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();