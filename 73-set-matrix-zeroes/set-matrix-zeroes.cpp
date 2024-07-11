class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size(), m = matrix[0].size(), col0 = -1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;

                    if(j==0) col0 = 0;
                    else matrix[0][j] = 0;
                }
            }
        }

        for(int i = n - 1; i > 0; i--){
            for(int j = m - 1; j > 0; j--){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i = m - 1; i >= 0; i--){
            if(matrix[0][0] == 0) matrix[0][i] = 0;
        }

        for(int i = n - 1; i >= 0; i--){
            if(col0 == 0) matrix[i][0] = 0;
        }
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();