class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis, int delRow[], int delCol[]){
        vis[r][c] = 1;

        for(int i = 0; i < 4; i++){
                int newRow = r + delRow[i];
                int newCol = c + delCol[i];

                if(newRow >= 0 && newCol >= 0 && newRow < board.size() && newCol < board[0].size() && board[newRow][newCol] == 'O' && !vis[newRow][newCol] ){
                    dfs(newRow, newCol, board, vis, delRow, delCol);
                }
            }

    }

    void solve(vector<vector<char>>& board) { 
        int tRows = board.size();
        int tCols = board[0].size();
        vector<vector<int>>vis(tRows, vector<int>(tCols, 0));
        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, -1, 0, 1};


        for(int i = 0; i < tRows; i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i, 0, board, vis, delRow, delCol);
            }
            
            if(board[i][tCols-1] == 'O' && !vis[i][tCols-1]){
                dfs(i, tCols-1, board, vis, delRow, delCol);
            }
        }

        for(int i = 0; i < tCols; i++){
            if(board[0][i] == 'O' && !vis[0][i]){
                dfs(0, i, board, vis, delRow, delCol);
            }
            
            if(board[tRows-1][i] == 'O' && !vis[tRows-1][i]){
                dfs(tRows-1, i, board, vis, delRow, delCol);
            }
        }

        for(int i = 0; i < tRows; i++){
            for(int j = 0; j < tCols; j++){
                if(board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};