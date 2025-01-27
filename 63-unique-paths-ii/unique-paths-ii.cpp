class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]) return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int>prev(n, 0);

        for(int i = 0; i < m; i++){
            vector<int>temp(n, 0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) temp[j] = 1;
                else{
                    int up = 0, left = 0;
                    if(i > 0 && obstacleGrid[i-1][j]!=1) up = prev[j];
                    if(j > 0 && obstacleGrid[i][j-1]!=1) left = temp[j-1];
                    temp[j] = up + left;
                }
            }
            prev = temp;
        }

        return obstacleGrid[m-1][n-1] == 1 ? 0 : prev[n-1];
    }
};