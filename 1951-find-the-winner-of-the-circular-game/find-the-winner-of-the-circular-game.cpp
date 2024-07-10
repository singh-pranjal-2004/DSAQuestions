class Solution {
public:
    int finder(int n, int k){
        if(n==1) return 0;

        int index = finder(n-1, k);
        index = (index + k) % n;
        return index;
    }

    int findTheWinner(int n, int k) {
        int ans = finder(n, k);
        return ans+1;
    }
};