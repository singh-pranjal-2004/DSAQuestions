class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses);

        for(auto& vec: prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            inDegree[a]++;
        }

        vector<int> topo;
        queue<int>q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for(auto& v: adj[u]) {
                inDegree[v]--;
                if(inDegree[v] == 0) 
                    q.push(v);
            }
        }

        if(topo.size() == numCourses)
            return topo;

        return {};
    }
};