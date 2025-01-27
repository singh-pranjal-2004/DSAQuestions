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

        // if(m == 1 && n == 1){
        //     if(obstacleGrid[0][0]) return 0;
        //     return 1;
        // }

        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solver(obstacleGrid, dp, m-1, n-1);
    }
};