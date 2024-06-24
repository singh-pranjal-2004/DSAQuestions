class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flips = 0, count = 0, n = nums.size();

        for(int i = 0;i<n;i++){
            if(i>=k && nums[i-k]==5){
                count--;
            }

            if(count%2==nums[i]){
                if(i+k>n) return -1;
                count++;
                flips++;
                nums[i] = 5;
            }
        }
        return flips;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();