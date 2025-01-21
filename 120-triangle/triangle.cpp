class Solution {
public:
    int solver(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j){
        if (i == triangle.size() - 1) {
            return triangle[i][j];
        }

        if(dp[i][j] != -1) return dp[i][j];
        
        int left = solver(triangle, dp, i + 1, j);
        int right = solver(triangle, dp, i + 1, j + 1);
        
        return dp[i][j] = triangle[i][j] + min(left, right);

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>>dp(n, vector<int>(n, -1));

        int ans = solver(triangle, dp, 0, 0);

        return ans;
    }
};