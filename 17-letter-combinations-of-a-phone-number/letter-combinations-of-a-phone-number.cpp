class Solution {
private:
    void solve(vector<string> &comb, string digits, string output, int i, string mapping[10]){
        if(i>=digits.length()){
            comb.push_back(output);
            return;
        }

        int dig = digits[i] - '0';
        for(int j = 0;j<mapping[dig].length();j++){
            output.push_back(mapping[dig][j]);
            solve(comb, digits, output, i+1, mapping);
            output.pop_back();
        }


    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> comb;
        if(digits.length()==0){
            return comb;
        }
        string output = ""; 
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};  
        solve(comb, digits, output, index , mapping);
        return comb;
    }
};