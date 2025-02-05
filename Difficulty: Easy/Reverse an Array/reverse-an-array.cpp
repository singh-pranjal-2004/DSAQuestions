//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solver(vector<int>& arr, int start, int end) {
        if(start >= end) return;
        
        swap(arr[start], arr[end]);
        
        solver(arr, start+1, end-1);
    }
    
    void reverseArray(vector<int> &arr) {
        // code here
        int start = 0, end = arr.size()-1;
        solver(arr, start, end);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends