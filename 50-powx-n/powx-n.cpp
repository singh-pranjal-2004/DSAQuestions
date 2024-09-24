class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) x = 1 / x;

        long nums = labs(n);

        double pow = 1;

        while(nums){
            if(nums & 1){
                pow *= x;
            }

            x *= x;
            nums >>= 1;
        }

        return pow;
    }
};