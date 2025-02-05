class Solution {
public:
    double solver(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;

        double half = solver(x, n/2);

        if(n % 2 == 0) {
            return half * half;
        }else {
            if(n < 0) {
                return half * half * 1/x;
            }else{
                return half * half * x;
            }
        }
    }

    double myPow(double x, int n) {
        return solver(x, n);
    }
};