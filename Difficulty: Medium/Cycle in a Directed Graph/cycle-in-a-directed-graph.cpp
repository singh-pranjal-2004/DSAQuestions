//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool detect(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& inRec, int node) {
        vis[node] = true;
        inRec[node] = true;
        
        for(int &adjNode : adj[node]) {
            if(!vis[adjNode] && detect(adj, vis, inRec, adjNode)) {
                return true;
            } else if(inRec[adjNode]) {
                return true;
            }
        }
        
        inRec[node] = false;
        
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<bool>vis(V, 0);
        vector<bool>inRec(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!vis[i] && detect(adj, vis, inRec, i))
                return true;
        }
        
        return false;
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