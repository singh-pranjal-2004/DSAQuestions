//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solver(vector<int>& height, vector<int>& dp, int n, int idx){
        if(idx == n-1) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int one, two = INT_MAX;
        
        one = solver(height, dp, n, idx+1) + abs(height[idx] - height[idx+1]);
        
        if(idx < n-2) two = solver(height, dp, n, idx+2) + abs(height[idx] - height[idx+2]);
        
        return dp[idx] = min(one, two);
    }
  
    int minCost(vector<int>& height) {
        int n = height.size();
        // Code here
        vector<int>dp(n, -1);
        
        return solver(height, dp, n, 0);
    }
};

//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends