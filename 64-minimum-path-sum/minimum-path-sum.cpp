class Solution {
public:
    int solver(vector<vector<int>>& grid, vector<vector<int>>& dp, int m, int n){
        if(m == 0 & n == 0) return grid[0][0];

        if(dp[m][n] != -1) return dp[m][n];

        int up = INT_MAX, left = INT_MAX;
        if(m > 0) up = grid[m][n] + solver(grid, dp, m-1, n);
        if(n > 0) left = grid[m][n] + solver(grid, dp, m, n-1);

        return dp[m][n] = min(up, left); 
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solver(grid, dp, m-1, n-1);
    }
};