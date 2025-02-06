//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solver(int num, char str[], vector<string>& ans, int i) {
        if(i == num) {
            str[i] = '\0';
            ans.push_back(str);
            return;
        }
        
        if(str[i-1] == '0') {
            str[i] = '0';
            solver(num, str, ans, i+1);
            
            str[i] = '1';
            solver(num, str, ans, i+1);
        }else if(str[i-1] == '1') {
            str[i] = '0';
            solver(num, str, ans, i+1);
        }
    }

    vector<string> generateBinaryStrings(int num){
        //Write your code
        vector<string>ans;
        
        char str[num + 1];
        
        str[0] = '0';
        solver(num, str, ans, 1);
        
        str[0] = '1';
        solver(num, str, ans, 1);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends