class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flips = 0, count = 0, n = nums.size();
        deque<int>flipQue;
        for(int i = 0;i<n;i++){
            if(i>=k){
                count-=flipQue.front();
                flipQue.pop_front();
            }

            if(count%2==nums[i]){
                if(i+k>n) return -1;
                count++;
                flips++;
                flipQue.push_back(1);
            }else{
                flipQue.push_back(0);
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