class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i = 0, j = 0;
        while(i<arr.size() && j<arr.size()){
            if(arr[j]%2==1){
                if(j-i==2){
                    return true;
                }
                j++;
            }else{
                j++;
                i = j;
            }
        }
        return false;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();