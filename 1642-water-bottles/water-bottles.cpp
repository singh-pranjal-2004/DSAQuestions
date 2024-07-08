class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drinked = 0;
        while(numBottles >= numExchange){
            drinked += numExchange;
            numBottles -= numExchange;
            numBottles++;
        }
        return drinked + numBottles;
    }
};