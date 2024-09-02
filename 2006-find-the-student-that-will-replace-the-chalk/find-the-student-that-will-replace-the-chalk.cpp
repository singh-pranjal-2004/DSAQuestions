class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int i: chalk){
            sum += i;
        }

        int rem = k % sum;

        for(int i = 0; i < chalk.size(); i++){
            if(rem < chalk[i]) return i;

            rem -= chalk[i];
        }

        return 0;
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();