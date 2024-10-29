class Solution {
public:
    int solver(vector<vector<int>>& grid, vector<vector<int>>& dp, int n, int m, int row, int col){
        if(row >= n || row < 0 || col >= m) return 0;

        if(dp[row][col] != -1) return dp[row][col];

        int first = 0, second = 0, third = 0;

        if(col+1 < m && row-1 >= 0 && grid[row][col] < grid[row-1][col+1]){
            first = solver(grid, dp, n, m, row-1, col+1) + 1;
        }

        if(col+1 < m && grid[row][col] < grid[row][col+1]){
            second = solver(grid, dp, n, m, row, col+1) + 1;
        }

        if(row+1 < n && col+1 < m && grid[row][col] < grid[row+1][col+1]){
            third = solver(grid, dp, n, m, row+1, col+1) + 1;
        }
        
        return dp[row][col] = max({first, second, third});

    }

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));

        int ans = 0;
        for(int i = 0; i < n; i++){
            int temp = solver(grid, dp, n, m, i, 0);
            ans = max(ans, temp);
        }

        return ans;
    }
};