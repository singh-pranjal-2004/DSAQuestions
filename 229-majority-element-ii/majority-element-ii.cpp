class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int number1 = 0, number2 = 0, count1 = 0, count2 = 0, n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(count1 == 0 && number2 != nums[i]){
                count1 = 1;
                number1 = nums[i];
            }else if(count2 == 0 && number1 != nums[i]){
                count2 = 1;
                number2 = nums[i];
            }else if(number1 == nums[i]){
                count1++;
            }else if(number2 == nums[i]){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }

        int threshold = n / 3;
        count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == number1) count1++;
            else if(nums[i] == number2) count2++;
        }

        if(count1 > threshold) ans.push_back(number1);
        if(count2 > threshold) ans.push_back(number2);

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();