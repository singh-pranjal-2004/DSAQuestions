class Solution {
public:
    void dfs(vector<vector<int>>& land, vector<vector<int>>& vis, int row, int col, int& ti, int& tj, int& bi, int& bj){
        vis[row][col] = 1;

        if(row < ti){
            ti = row;
        }

        if(col < tj){
            tj = col;
        }

        if(row > bi){
            bi = row;
        }

        if(col > bj){
            bj = col;
        }
        
        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int newR = row + delRow[i];
            int newC = col + delCol[i];

            if(newR >= 0 && newC >= 0 && newR < land.size() && newC < land[0].size() && land[newR][newC] == 1 && !vis[newR][newC]){
                dfs(land, vis, newR, newC, ti, tj, bi, bj);
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        int n = land.size(), m = land[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(land[i][j] == 1 && !vis[i][j]){
                    int ti = i, tj = j, bi = i, bj = j;
                    dfs(land, vis, i, j, ti, tj, bi, bj);
                    vector<int>temp;
                    temp.push_back(ti);
                    temp.push_back(tj);
                    temp.push_back(bi);
                    temp.push_back(bj);
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();