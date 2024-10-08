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