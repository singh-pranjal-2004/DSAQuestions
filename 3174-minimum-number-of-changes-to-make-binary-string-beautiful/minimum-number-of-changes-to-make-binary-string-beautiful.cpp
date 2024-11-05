class Solution {
public:
    int minChanges(string s) {
        int count = 1, ans = 0;
        char c = s[0];

        for(int i = 1; i < s.length(); i++){
            if(s[i] == c){
                count++;
            }else if(s[i] != c){
                if(count % 2 == 0){
                    count = 1;
                    c = s[i];
                }else{
                    (s[i] == '1') ? s[i] = '0' : s[i] = '1';
                    count++;
                    ans++;
                }
            }
        }
        return ans;
    }
};