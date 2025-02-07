class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int u, int col) {
        color[u] = col;

        for(auto& v: graph[u]) {
            int colV = 1 - col;
            if(color[v] == col) {
                return false;
            }else if(color[v] == -1 && !dfs(graph, color, v, colV)) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);

        for(int i = 0; i < n; i++) {
            if(color[i] == -1 && !dfs(graph, color, i, 0)) {
                return false;
            }
        }

        return true;
    }
};