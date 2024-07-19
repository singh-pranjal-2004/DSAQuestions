class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_map<int, pair<int, int>>mp;
        vector<int>ans;

        for(int i = 0; i < matrix.size(); i++){
            int minVal = matrix[i][0];
            int minIndex = 0;
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j] < minVal){
                    minVal = matrix[i][j];
                    minIndex = j;
                }
            }
            mp[minVal] = {i, minIndex};
        }

        for(int i = 0; i < matrix[0].size(); i++){
            int maxVal = matrix[0][i];
            int maxIndex = 0;
            for(int j = 1; j < matrix.size(); j++){
                if(matrix[j][i] > maxVal){
                    maxVal = matrix[j][i];
                    maxIndex = j;
                }
            }

            if(mp.find(maxVal) != mp.end()){
                int a = mp[maxVal].first;
                int b = mp[maxVal].second;

                if(a == maxIndex && b == i){
                    ans.push_back(maxVal);
                }
            }

        }

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();