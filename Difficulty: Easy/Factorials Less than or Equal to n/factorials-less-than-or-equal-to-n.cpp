//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void solver(vector<long long>& ans, long long n, long long fact, long long i) {
        if(fact > n) return;
        
        ans.push_back(fact);
        
        solver(ans, n, fact * (i+1), i+1);
    }
   
    vector<long long> factorialNumbers(long long n) {
        // Write Your Code here
        vector<long long>ans;

        solver(ans, n, 1, 1);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends