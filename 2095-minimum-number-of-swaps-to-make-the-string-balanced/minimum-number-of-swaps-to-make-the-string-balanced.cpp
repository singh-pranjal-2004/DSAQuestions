class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        int ans = 0;

        for(auto ch: s){
            if(ch == '['){
                ans++;
            }else if(ans > 0) ans--;
        }

        return (ans + 1) / 2;
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();