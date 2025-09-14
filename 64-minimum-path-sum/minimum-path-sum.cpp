class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int>dp(n, 0);
        dp[0] = grid[0][0];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0)
                    continue;

                int top = INT_MAX, left = INT_MAX;
                if(i > 0) top = grid[i][j] + dp[j];
                if(j > 0) left = grid[i][j] + dp[j-1];

                dp[j] = min(top, left);
            }
        }

        return dp[n-1];
    }
};