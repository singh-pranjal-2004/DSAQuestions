class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int tRows = mat.size();
        int tCols = mat[0].size();
        vector<vector<int>> vis(tRows, vector<int>(tCols, 0));
        vector<vector<int>>dist(tRows, vector<int>(tCols));
        
        queue<pair<pair<int, int>, int>>q;
        
        for(int i = 0; i < tRows; i++){
            for(int j = 0; j < tCols; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            dist[row][col] = dis;
            
            int cRows[4] = {-1, 0, 1, 0};
            int cCols[4] = {0, 1, 0, -1};
            
            for(int i = 0; i < 4; i++){
                int newRow = row + cRows[i];
                int newCol = col + cCols[i];
                
                if(newRow >= 0 && newCol >= 0 && newRow < tRows && newCol < tCols && vis[newRow][newCol] == 0){
                    q.push({{newRow, newCol}, dis+1});
                    vis[newRow][newCol] = 1;
                }
            }
        }
        return dist;
    }
};