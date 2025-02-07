class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& inRecursion, stack<int>& st, int u) {
        vis[u] = true;
        inRecursion[u] = true;

        for(auto& v: adj[u]) {
            if(!vis[v] && dfs(adj, vis, inRecursion, st, v)) {
                return true;
            }else if(inRecursion[v]) {
                return true;
            }
        }

        st.push(u);
        inRecursion[u] = false;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(auto& vec: prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
        }

        vector<bool>vis(numCourses, false);
        vector<bool>inRecursion(numCourses, false);
        stack<int>st;
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i] && dfs(adj, vis, inRecursion, st, i))
                return {};
        }

        vector<int>ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;

    }
};