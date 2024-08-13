class Solution {
public:
    void solver(int index, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& comb, int target){
        if(target == 0){
            ans.push_back(comb);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]) continue;

            if(candidates[i] > target) break;

            comb.push_back(candidates[i]);
            solver(i+1, candidates, ans, comb, target - candidates[i]);
            comb.pop_back();
        } 
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));

        vector<vector<int>>ans;
        vector<int>comb;
        // 1 1 2 5 6 7 10

        solver(0, candidates, ans, comb, target);

        return ans;
    }
};