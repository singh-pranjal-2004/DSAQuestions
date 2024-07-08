class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drinked = numBottles;

        while(numBottles >= numExchange){
            int q = numBottles / numExchange;
            int r = numBottles % numExchange;
            drinked += q;
            numBottles /= numExchange;
            numBottles += r;
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