class Solution {
public:
    int solver(vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp, int m, int n){
        if(m < 0 || n < 0 || obstacleGrid[m][n] == 1) return 0;
        if(m == 0 && n == 0) return 1;

        if(dp[m][n] != -1) return dp[m][n];

        int up = solver(obstacleGrid, dp, m-1, n);
        int left = solver(obstacleGrid, dp, m, n-1);

        return dp[m][n] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>>dp(m, vector<int>(n, -1));

        if(obstacleGrid[0][0]) return 0;

        dp[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;
                int up = 0, left = 0;
                if(i > 0 && obstacleGrid[i-1][j]!=1) up = dp[i-1][j];
                if(j > 0 && obstacleGrid[i][j-1]!=1) left = dp[i][j-1];

                dp[i][j] = up + left;
            }
        }

        return obstacleGrid[m-1][n-1] == 1 ? 0 : dp[m-1][n-1];
    }
};