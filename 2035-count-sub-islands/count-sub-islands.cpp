class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,
             vector<vector<int>>& vis, int delRow[], int delCol[], int row,
             int col, int n, int m, bool& isValid) {
        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m &&
                grid2[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                if (grid1[newRow][newCol] == 0)
                    isValid = false;
                dfs(grid1, grid2, vis, delRow, delCol, newRow, newCol, n, m,
                    isValid);
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool isValid = true;
                if (grid2[i][j] == 1 && !vis[i][j]) {
                    if(grid1[i][j] == 0){
                        isValid = false;
                    }
                    
                    dfs(grid1, grid2, vis, delRow, delCol, i, j, n, m, isValid);
                    if (isValid){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();