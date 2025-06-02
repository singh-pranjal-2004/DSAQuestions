class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>reqCandy(n, 1);

        for(int i = 1; i < n; i++) {
            if(ratings[i-1] < ratings[i]) {
                reqCandy[i] = reqCandy[i-1] + 1;
            }
        }

        for(int i = n-2; i >= 0; i--) {
            if(ratings[i+1] < ratings[i]) {
                reqCandy[i] = max(reqCandy[i], reqCandy[i+1]+1);
            }
        }

        return accumulate(reqCandy.begin(), reqCandy.end(), 0);
    }
};