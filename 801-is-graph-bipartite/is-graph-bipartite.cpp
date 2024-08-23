class Solution {
public:
    bool check(int start, vector<vector<int>>& graph, vector<int>& vis){
        queue<int>q;

        vis[start] = 0;
        q.push(start);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto i: graph[node]){
                if(vis[i] != -1 && vis[node] == vis[i]) return false;

                if(vis[i] != -1) continue;
                vis[i] = !vis[node];
                q.push(i);
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n, -1);
        
        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                if(check(i, graph, vis) == false) return false;
            }
        }

        return true;
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();