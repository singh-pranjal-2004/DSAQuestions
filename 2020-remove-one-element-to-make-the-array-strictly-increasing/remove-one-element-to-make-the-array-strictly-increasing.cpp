class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            bool check = true;
            int pre = (i==0) ? 0 : nums[0];
            
            for(int j = 1; j < nums.size(); j++){
                if(j == i){
                    continue;
                }

                if(pre >= nums[j]){
                    check = false;
                    break;
                }

                pre = nums[j];
            }

            if(check) return true;
        }

        return false;
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();