class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return false;
        int n = grid.size();
        int t = n*n;
        int row = 0, col = 0;
        for(int i = 0; i < t; i++){
            if(row-2>=0 && col-1>=0 && grid[row-2][col-1] == i+1){
                row = row - 2;
                col = col - 1;
            }else if(row-2>=0 && col+1<n && grid[row-2][col+1]==i+1){
                row = row - 2;
                col = col + 1;
            }else if(row-1>=0 && col-2>=0 && grid[row-1][col-2]==i+1){
                row = row - 1;
                col = col - 2;
            }else if(row-1>=0 && col+2<n && grid[row-1][col+2]==i+1){
                row = row - 1;
                col = col + 2;
            }else if(col-2>=0 && row+1<n && grid[row+1][col-2]==i+1){
                row = row + 1;
                col = col -2;
            }else if(row+1<n && col+2<n && grid[row+1][col+2]==i+1){
                row = row + 1;
                col = col + 2;
            }else if(col-1>=0 && row+2<n && grid[row+2][col-1]==i+1){
                row = row + 2;
                col = col - 1;
            }else if(row+2<n && col+1<n && grid[row+2][col+1]==i+1){
                row = row + 2;
                col = col + 1;
            }else if(i == t-1) return true;
            else return false;
        }
        return true;
        
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();