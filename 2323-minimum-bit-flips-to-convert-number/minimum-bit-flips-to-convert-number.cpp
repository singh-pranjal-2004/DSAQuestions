class Solution {
public:
    int minBitFlips(int start, int goal) {
        if(start == goal) return 0;

        int xorValue = start ^ goal;
        int count = 0;
        while(xorValue){
            count += (xorValue & 1);
            xorValue >>= 1;
        }

        return count;
    }
};