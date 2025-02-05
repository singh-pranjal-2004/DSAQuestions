class Solution {
public:
    int M = 1e9+7;
    long long solver(long long givenPoss, long long n, long long ans) {
        if(n == 0) return ans;

        if(n & 1) {
            return solver(givenPoss, n-1, (ans*givenPoss) % M);
        }else return solver((givenPoss * givenPoss) % M, n/2, ans);
    }

    int countGoodNumbers(long long n) {
        long long temp = solver(20, n/2, 1);

        return n&1 ? (temp * 5 % M) : temp;
    }
};