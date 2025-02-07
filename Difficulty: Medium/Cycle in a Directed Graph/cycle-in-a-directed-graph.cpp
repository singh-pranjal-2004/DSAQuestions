//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<int>inDegree(V, 0);
        for(int i = 0; i < V; i++) {
            for(auto& v: adj[i]) {
                inDegree[v]++;
            }
        }
        
        int count = 0;
        queue<int>q;
        
        for(int i = 0; i < V; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
                count++;
            }
        }
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            for(auto& v: adj[u]) {
                inDegree[v]--;
                if(inDegree[v] == 0) {
                    q.push(v);
                    count++;
                }
            }
        }
        
        return count != V;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends