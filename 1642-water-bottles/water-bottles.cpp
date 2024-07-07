class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + ((numBottles-1) / (numExchange-1));
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();