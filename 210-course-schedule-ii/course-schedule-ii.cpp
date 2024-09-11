class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int>inDegree(numCourses, 0);

        for(auto i: prerequisites){
            adj[i[1]].push_back(i[0]);
            inDegree[i[0]]++;
        }

        queue<int>q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0) q.push(i);
        }

        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto adjacent: adj[node]){
                inDegree[adjacent]--;
                if(inDegree[adjacent] == 0) q.push(adjacent);
            }
        }

        return (topo.size()==numCourses)? topo : vector<int>{} ;
    }
};

