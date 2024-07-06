class Solution {
public:
    int passThePillow(int n, int time) {
        int ans = 0;
        for(int i = 0; i <= time; i++){
            ans++;
            if(ans==-1 || ans == n) ans*=-1;
        }
        return abs(ans);
    }
};