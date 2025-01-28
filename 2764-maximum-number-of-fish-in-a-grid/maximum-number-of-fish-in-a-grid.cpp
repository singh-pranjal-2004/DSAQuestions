class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int m, int n, int i, int j) {
        int ti[] = {-1, 0, 1, 0};
        int tj[] = {0, 1, 0, -1};
        int ans = grid[i][j];

        vis[i][j] = 1;

        for(int k = 0; k < 4; k++){
            int ni = ti[k] + i;
            int nj = tj[k] + j;

            if(ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj]!=0 && !vis[ni][nj]){
                ans += dfs(grid, vis, m, n, ni, nj);
            }
        }

        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int maxi = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]!=0 && !vis[i][j]) maxi = max(maxi, dfs(grid, vis, m, n, i, j));
            }
        }

        return maxi;
    }
};