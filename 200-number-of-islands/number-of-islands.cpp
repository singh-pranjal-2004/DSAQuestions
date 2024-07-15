class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis, int m, int n){
        if(row < 0 || row >= m ||
                col < 0 || col >= n ||
                vis[row][col] || grid[row][col] != '1'){
                    return;
        }

        vis[row][col] = 1;
        dfs(row - 1, col, grid, vis, m, n);
        dfs(row + 1, col, grid, vis, m, n);
        dfs(row, col - 1, grid, vis, m, n);
        dfs(row, col + 1, grid, vis, m, n);
        
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