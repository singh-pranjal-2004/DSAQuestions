class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0, counter = 0;
        for(int i = s.length()-1; i >= 0; i--){
            if(s[i] == '1') ans += counter;
            else counter++;
        }

        return ans;
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();