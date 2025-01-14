//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    static bool customComparator(const string& str1, const string& str2){
        return (str1 + str2) > (str2 + str1);
    }
    
    string findLargest(vector<int> &arr) {
        // code here
        vector<string>tArr;
        for(auto i: arr){
            tArr.push_back(to_string(i));
        }
        
        sort(tArr.begin(), tArr.end(), customComparator);
        
        string str = "";
        
        for(auto i: tArr){
            str += i;
        }
        
        if(str[0] == '0') return "0";
        
        return str;
        
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
        string ans = ob.findLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends