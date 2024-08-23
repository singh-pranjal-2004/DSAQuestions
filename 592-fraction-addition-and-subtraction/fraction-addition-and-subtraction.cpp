class Solution {
public:
    string fractionAddition(string expression) {
        int s = expression.size();
        int i = 0;
        int ntr = 0, dtr = 1;
        while(i < s){
            int sign = 1;
            int n = 0, d = 0;

            if(expression[i] == '-'){
                sign = -1;
                i++;
            }else if(expression[i] == '+'){
                i++;
            }

            while(isdigit(expression[i])){
                n = n * 10 + (expression[i]-'0');
                i++;
            }
            n *= sign;

            i++;

            while(isdigit(expression[i])){
                d = d * 10 + (expression[i]-'0');
                i++;
            }

            ntr = ntr * d;
            n = n * dtr;
            ntr += n;
            dtr = dtr * d;

            int gd = gcd(abs(ntr), dtr);
            ntr /= gd;
            dtr /= gd;
            
        }

        return to_string(ntr) + "/" + to_string(dtr);
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();