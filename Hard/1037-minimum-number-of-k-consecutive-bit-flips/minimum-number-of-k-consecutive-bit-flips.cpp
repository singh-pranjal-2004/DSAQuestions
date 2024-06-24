class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flips = 0, count = 0, n = nums.size();
        vector<bool> isFlipped(n, false);

        for(int i = 0;i<n;i++){
            if(i>=k && isFlipped[i-k]==true){
                count--;
            }

            if(count%2==nums[i]){
                if(i+k>n) return -1;
                count++;
                flips++;
                isFlipped[i] = true;
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