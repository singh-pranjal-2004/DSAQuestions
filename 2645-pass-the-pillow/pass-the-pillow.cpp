class Solution {
public:
    int passThePillow(int n, int time) {
        int fullRound = time / (n-1);
        int timeLeft = time % (n-1);

        if(fullRound%2==0){
            return timeLeft+1;
        }else return n-timeLeft;
    }
};