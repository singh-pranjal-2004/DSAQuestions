class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& inRecur, int u) {
        vis[u] = true;
        inRecur[u] = true;

        for(auto& v: adj[u]) {
            if(!vis[v]) {
                if(dfs(adj, vis, inRecur, v))
                    return true;
            }else if(inRecur[v]) {
                return true;
            }
        }

        inRecur[u] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(auto& vec: prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
        }

        vector<bool>vis(numCourses, false);
        vector<bool>inRecur(numCourses, false);

        for(int i = 0; i < numCourses; i++) {
            if(!vis[i])
                if(dfs(adj, vis, inRecur, i) == true) return false;
        }

        return true;
    }
};