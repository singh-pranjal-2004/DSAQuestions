class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adj(n);

        for(int u = 0; u < n; u++) {
            for(int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i]; 
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        vector<int>vis(n, -1);

        for(int i = 0; i < n; i++) {
            if(vis[i] == -1) {
                queue<pair<int, int>>q;
                q.push({i, 0});
                vis[i] = 0;

                while(!q.empty()) {
                    int v = q.front().first;
                    int col = q.front().second;
                    vis[v] = col;
                    q.pop();

                    for(auto u: adj[v]) {
                        if(vis[u] == col) return false;

                        if(vis[u] == -1) {
                            q.push({u, 1-col});
                        }
                    }
                }
            }
        }

        return true;
    }
};