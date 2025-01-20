class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int n = 0, m = x;

        while(x){
            int temp = x % 10;

            if(n > (INT_MAX/10) || n < (INT_MIN/10)) return 0;

            n = n * 10 + temp;

            x /= 10;
        }

        if(m == n) return true;
        return false;
    }
};