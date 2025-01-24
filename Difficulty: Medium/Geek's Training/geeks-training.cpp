//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solver(vector<vector<int>>& points, vector<vector<int>>& dp, int n, int idx, int last){
        if(idx == 0) {
            int maxi = INT_MIN;
            for(int i = 0; i < 3; i++){
                if(i != last) maxi = max(maxi, points[0][i]);
            }
    
            return maxi;
        }
        
        if(dp[idx][last] != -1) return dp[idx][last];
    
        int ans = INT_MIN;
        for(int i = 0; i < 3; i++){
            if(i != last){
                int temp = points[idx][i] + solver(points, dp, n, idx-1, i);
                ans = max(ans, temp);
            }
        }
    
        return dp[idx][last] = ans;
    }

    int maximumPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solver(points, dp, n, n-1, 3);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends