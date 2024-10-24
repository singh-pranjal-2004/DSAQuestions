//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solver(vector<int>& arr, vector<int>& dp, int k, int n){
        if(n == 0) return 0;
        if(k <= 0) return INT_MAX;
        
        if(dp[n] != -1) return dp[n];
        
        int toS = INT_MAX;
        for(int i = 1; i <= k && n-i >= 0; i++){
            int temp = solver(arr, dp, k, n-i) + abs(arr[n] - arr[n-i]);
            toS = min(toS, temp);
        }
        
        return dp[n] = toS;
    }
  
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int>dp(n, -1);
        return solver(arr, dp, k, n-1);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends