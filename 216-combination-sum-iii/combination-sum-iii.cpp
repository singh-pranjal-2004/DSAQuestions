class Solution {
public:
    void solver(vector<vector<int>>& ans, vector<int>& temp, int k, int n, int i) {
        if(n == 0 && temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        for(int j = i; j <= 9; j++) {
            // if(n-j < 0 && temp.size() > k-1) break;

            temp.push_back(j);
            solver(ans, temp, k, n-j, j+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>temp;

        solver(ans, temp, k, n, 1);

        return ans;
    }
};