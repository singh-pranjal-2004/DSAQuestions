class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>>dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) dp[0][i] = matrix[0][i];

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int left = (j > 0)? dp[i-1][j-1] : INT_MAX;
                int right = (j < n-1)? dp[i-1][j+1] : INT_MAX;

                int top = dp[i-1][j];

                dp[i][j] = matrix[i][j] + min(top, min(left, right));
            }
        }

        for(int i = 0; i < n; i++){
            mini = min(mini, dp[n-1][i]);
        }

        return mini;
    }
};