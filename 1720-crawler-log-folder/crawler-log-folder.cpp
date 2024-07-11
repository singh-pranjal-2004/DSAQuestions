class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for(auto str: logs){
            if(str=="../") depth = max(0, depth - 1);
            else if(str=="./") continue;
            else depth++;
        }

        return depth;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();