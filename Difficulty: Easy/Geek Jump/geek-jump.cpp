//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // int solver(vector<int>& height, int n, vector<int>&dp){
    //     if (n == 0) return 0;
        
    //     if(dp[n] != -1) return dp[n];
        
    //     int two = INT_MAX;
    //     int one = solver(height, n-1, dp) + abs(height[n] - height[n-1]);
    //     if(n > 1) two = solver(height, n-2, dp) + abs(height[n] - height[n-2]);
        
    //     return dp[n] = min(one, two);
    // }
    
    // int minimumEnergy(vector<int>& height, int n) {
    //     // Code here
    //     vector<int>dp(n, -1);
    //     return solver(height, n-1, dp);
    // }
    
    
    // ************************************************
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n, 0);
        
        for(int i = 1; i < n; i++){
            int fs = dp[i-1] + abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if(i > 1) ss = dp[i-2] + abs(height[i] - height[i-2]);
            
            dp[i] = min(fs, ss);
        }
        
        return dp[n-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends