class Solution {
public:
    bool possible(vector<int> position, int mid, int m){
        int prev = position[0], count = 1;
        for(int i = 0;i<position.size();i++){
            if(position[i]-prev >= mid){
                count++;
                prev = position[i];
            }
            if(count==m){
            return true;
        }
        }
        
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size(), low = 0, high = position[n-1], ans;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(possible(position, mid, m)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();