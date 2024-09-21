class Solution {
public:
    void solver(vector<int>& ans, int num, int n){
        if(num > n) return;
        if(num > 0) ans.push_back(num);
        
        for(int i = (num == 0) ? 1 : 0 ; i <= 9; i++){
            int x = num * 10 + i;
            if(x > n) break;
            solver(ans, x, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        solver(ans, 0, n);

        return ans;
    }
};