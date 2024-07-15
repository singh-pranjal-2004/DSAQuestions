class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis, int m, int n){
        vector<vector<int>> possibleDir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vis[row][col] = 1;

        for(int i = 0; i < 4; i++){
            int newRow = row + possibleDir[i][0];
            int newCol = col + possibleDir[i][1];

            if(newRow >= 0 && newRow < m &&
                newCol >= 0 && newCol < n &&
                !vis[newRow][newCol] && grid[newRow][newCol] == '1'){
                    dfs(newRow, newCol, grid, vis, m, n);
            }

        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m == 0) return 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    count++;
                    dfs(i, j, grid, vis, m, n);
                }
            }
        }

        return count;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();