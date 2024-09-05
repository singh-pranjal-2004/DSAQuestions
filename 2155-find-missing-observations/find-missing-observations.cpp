class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();

        int tSize = n + m;
        int tValue = mean * tSize;

        for(auto i: rolls){
            tValue -= i;
        }


        int val = tValue / n;
        int rem = tValue % n;

        if(6*n < tValue || tValue <= 0 || val == 0) return {};

        vector<int>ans(n, val);

        for(int i = 0; i < rem; i++){
            ans[i]++;
        }

        return ans;
    }
};