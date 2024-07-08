class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drinked = numBottles;
        int q;
        int r;

        while(numBottles >= numExchange){
            q = numBottles / numExchange;
            r = numBottles % numExchange;
            drinked += q;
            numBottles /= numExchange;
            numBottles += r;
            r = 0;
        }

        return drinked;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();