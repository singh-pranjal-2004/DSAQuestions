class Solution {
public:
    int solver(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int n){
        if(j < 0 || j >= n) return 1e9;
        if(i == n-1) return matrix[i][j];

        if(dp[i][j] != -1e9) return dp[i][j];

        int left = matrix[i][j] + solver(matrix, dp, i+1, j-1, n);
        int right = matrix[i][j] + solver(matrix, dp, i+1, j+1, n);

        int down = matrix[i][j] + solver(matrix, dp, i+1, j, n);

        return dp[i][j] = min(left, min(right, down));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = 1e9;
        vector<vector<int>>dp(n, vector<int>(n, -1e9));

        for(int i = 0; i < n; i++){
            int ans = solver(matrix, dp, 0, i, n);
            mini = min(mini, ans);
        }

        return mini;
    }
};