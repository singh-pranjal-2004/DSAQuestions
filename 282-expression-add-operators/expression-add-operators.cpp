class Solution {
public:
    void solver(vector<string>& ans, string num, int target, int i, string temp,
                long prev, long curr, bool isFirst) {
        if (i == num.size()) {
            if (curr == target)
                ans.push_back(temp);
            return;
        }

        for (int idx = i; idx < num.size(); idx++) {
            if (idx > i && num[i] == '0')
                break;

            string s = num.substr(i, idx - i + 1);
            long n = stol(s);

            if (i == 0) {
                solver(ans, num, target, idx + 1, s, n, n, false);
            } else {
                solver(ans, num, target, idx + 1, temp + "+" + s, n, curr + n,
                       false);
                solver(ans, num, target, idx + 1, temp + "-" + s, -n, curr - n,
                       false);
                solver(ans, num, target, idx + 1, temp + "*" + s, prev * n,
                       curr - prev + prev * n, false);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;

        solver(ans, num, target, 0, "", 0, 0, true);

        return ans;
    }
};