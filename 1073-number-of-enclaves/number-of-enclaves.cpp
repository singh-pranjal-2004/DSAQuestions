class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int tRows = board.size();
        int tCols = board[0].size();
        queue<pair<int, int>>q;
        vector<vector<int>>vis(tRows, vector<int>(tCols, 0));
        int ans = 0;

        for(int i = 0; i < tRows; i++){
            if(board[i][0] == 1 && !vis[i][0]){
                q.push({i, 0});
                vis[i][0] = 1;
            }
            
            if(board[i][tCols-1] == 1 && !vis[i][tCols-1]){
                q.push({i, tCols-1});
                vis[i][tCols-1] = 1;
            }
        }

        for(int i = 0; i < tCols; i++){
            if(board[0][i] == 1 && !vis[0][i]){
                q.push({0, i});
                vis[0][i] = 1;
            }
            
            if(board[tRows-1][i] == 1 && !vis[tRows-1][i]){
                q.push({tRows-1, i});
                vis[tRows-1][i] = 1;
            }
        }

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, -1, 0, 1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int newRow = r + delRow[i];
                int newCol = c + delCol[i];

                if(newRow >= 0 && newCol >= 0 && newRow < tRows && newCol < tCols && board[newRow][newCol] == 1 && !vis[newRow][newCol] ){
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = 1;
                }
            }
        }

        for(int i = 0; i < tRows; i++){
            for(int j = 0; j < tCols; j++){
                if(board[i][j] == 1 && !vis[i][j]) ans++;
            }
        }

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();