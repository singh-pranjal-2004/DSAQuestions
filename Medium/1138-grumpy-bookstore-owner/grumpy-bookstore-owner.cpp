class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int m = minutes;
        int count = 0;

        for(int i = 0;i<m;i++){
            count+=customers[i]*grumpy[i];
        }

        int maxUn = count;

        for(int i = 1, j = m;i<n-m+1;i++, j++){
            if(grumpy[i-1]==1){
                count-=customers[i-1];
            }
            
            count+= customers[j]*grumpy[j];

            maxUn = max(count, maxUn);
        }

        if(maxUn<0) maxUn = 0;

        for(int i = 0;i<n;i++){
            maxUn += customers[i] * (1-grumpy[i]);
        }

        return maxUn;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();