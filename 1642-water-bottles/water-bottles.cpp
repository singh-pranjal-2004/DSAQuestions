class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int rem = 0;
        ans+=numBottles;
        while(numBottles>=numExchange){
            ans += (numBottles/numExchange);
            rem += (numBottles % numExchange);
            numBottles/=numExchange;
            numBottles += rem;
            rem = 0;
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();