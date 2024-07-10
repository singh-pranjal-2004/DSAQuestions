class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v;
        for(int i = 1; i <= n; i++){
            v.push_back(i);
        }

        int index = 0;
        while(n>1){
            index = (index + k - 1) % n;
            v.erase(v.begin() + index);
            n--;
        }
        
        return v[0];
    }
};