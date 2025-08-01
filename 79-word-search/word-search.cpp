class Solution {
public:
    bool solver(vector<vector<char>>& board, vector<vector<bool>>& vis,
                string word, int i, int j, int m, int n, int wIdx) {
        if (wIdx == word.length())
            return true;

        if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] ||
            board[i][j] != word[wIdx])
            return false;

        vis[i][j] = true;
        int newRow[4] = {-1, 0, 1, 0};
        int newCol[4] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int nr = i + newRow[k], nc = j + newCol[k];
            if (solver(board, vis, word, nr, nc, m, n, wIdx + 1)) {
                // vis[i][j] = false;
                return true;
            }
        }

        vis[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (solver(board, vis, word, i, j, m, n, 0))
                    return true;
            }
        }

        return false;
    }
};