class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>arr(n, 0);
        for(auto &vec: roads){
            int u = vec[0];
            int v = vec[1];

            arr[u]++;
            arr[v]++;
        }

        sort(arr.begin(), arr.end());
        for(int i = 0;i<n;i++){
            cout<<arr[i]<<" ";
        }

        long long sum = 0;
        for(long long i = 1;i<=arr.size();i++){
            sum+=(i*arr[i-1]);
        }
        return sum;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();