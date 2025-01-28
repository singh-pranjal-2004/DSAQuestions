class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<int>dp(n, 0);

        for(int i = 0; i < n; i++) dp[i] = matrix[0][i];

        for(int i = 1; i < n; i++) {
            vector<int>temp(n, 0);
            for(int j = 0; j < n; j++) {
                int left = (j > 0)? dp[j-1] : INT_MAX;
                int right = (j < n-1)? dp[j+1] : INT_MAX;

                int top = dp[j];

                temp[j] = matrix[i][j] + min(top, min(left, right));
            }
            dp = temp;
        }

        for(int i = 0; i < n; i++){
            mini = min(mini, dp[i]);
        }

        return mini;
    }
};