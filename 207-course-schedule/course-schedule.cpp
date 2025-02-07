class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses);

        for(auto& vec: prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            inDegree[a]++;
        }

        queue<int>q;
        int count = 0;
        for(int i = 0; i < numCourses; i++) {
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

        if(count == numCourses)
            return true;

        return false;
    }
};