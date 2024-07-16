class Solution {
private:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, queue<vector<int>>& q, int& minute, int m, int n){
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int row = q.front()[0];
                int col = q.front()[1];
                int prevTime = q.front()[2];
                int delRow[] = {-1, +1, 0, 0};
                int delCol[] = {0, 0, -1, +1};

                for(int i = 0; i < 4; i++){
                    int r = row + delRow[i];
                    int c = col + delCol[i];

                    if(r >= 0 && r < m && c >= 0 && c < n && !vis[r][c] && grid[r][c] == 1){
                        vis[r][c] = 1;
                        grid[r][c] = 2;
                        q.push({r, c, prevTime+1});
                    }
                }
                q.pop();
                minute = max(minute, prevTime);
            }
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<vector<int>>q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({i, j, 0});
                }
            }
        }

        int minute = 0;
        bfs(grid, vis, q, minute, m, n);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return minute;
    }
};