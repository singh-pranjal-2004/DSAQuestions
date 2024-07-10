class Solution {
public:
    int minOperations(vector<string>& logs) {
        int c = 0;
        for(auto str: logs){
            if(str=="../") (c>0)?c--:c=0;
            else if(str=="./") continue;
            else c++;
        }

        return (c>=0)? c : 0;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();