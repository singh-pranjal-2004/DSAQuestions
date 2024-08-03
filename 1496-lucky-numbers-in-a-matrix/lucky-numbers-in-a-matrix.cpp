class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxMinRow = INT_MIN;
        for(int row = 0; row < m; row++){
            int minRow = INT_MAX;
            for(int col = 0; col < n; col++){
                minRow = min(minRow, matrix[row][col]);
            }

            maxMinRow = max(maxMinRow, minRow);
        }

        int minMaxCol = INT_MAX;
        for(int col = 0; col < n; col++){
            int maxCol = INT_MIN;
            for(int row = 0; row < m; row++){
                maxCol = max(maxCol, matrix[row][col]);
            }

            minMaxCol = min(minMaxCol, maxCol);
        }

        if(minMaxCol == maxMinRow) return {minMaxCol};

        return {};
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();