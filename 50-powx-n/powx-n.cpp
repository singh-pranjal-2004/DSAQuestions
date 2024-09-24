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

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();