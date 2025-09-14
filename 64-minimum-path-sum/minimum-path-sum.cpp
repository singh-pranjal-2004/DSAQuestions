class Solution {
public:
    int solver(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp) {
        if(m == 0 && n == 0)
            return grid[0][0];

        if(dp[m][n] != -1)
            return dp[m][n];

        int up = INT_MAX, left = INT_MAX;

        if(m > 0)
            up = grid[m][n] + solver(grid, m-1, n, dp);
        if(n > 0)
            left = grid[m][n] + solver(grid, m, n-1, dp);

        return dp[m][n] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solver(grid, m-1, n-1, dp);
    }
};