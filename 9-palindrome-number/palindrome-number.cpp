class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long n = 0, m = x;

        while(x){
            long long temp = x % 10;

            n = n * 10 + temp;

            x /= 10;
        }

        return (m == n);
    }
};