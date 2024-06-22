class Solution {
public:
    int solver(vector<int> nums, int k){
        if(k<0) return 0;

        int left = 0, right = 0, sum = 0, count = 0;
        while(right<nums.size()){
            sum += nums[right];

            while(sum>k){
                sum -= nums[left];
                left++;
            }

            count += (right-left+1);
            right++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i = 0;i<nums.size();i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }else{
                nums[i]=1;
            }
        }
        return solver(nums, k) - solver(nums, k-1);
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

