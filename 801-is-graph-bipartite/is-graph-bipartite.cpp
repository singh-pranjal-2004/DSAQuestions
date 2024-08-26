class Solution {
public:
    bool dfs(int start, vector<vector<int>>& graph, vector<int>& vis, int col){
        vis[start] = !col;

        for(auto i: graph[start]){
            if(vis[i] == -1){
                if(dfs(i, graph, vis, !col) == false) return false;
            }else if(vis[i] != -1 && vis[i] == vis[start]) return false;
        }

        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n, -1);
        
        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                if(dfs(i, graph, vis, 0) == false) return false;
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