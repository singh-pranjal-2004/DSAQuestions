class Solution {
public:
    // Using BFS (Topo Sort)
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>adj[graph.size()];
        vector<int>inDegree(graph.size(), 0);
        for(int i = 0; i < graph.size(); i++){
            for(auto it: graph[i]){
                adj[it].push_back(i);
                inDegree[i]++;
            }
        }
        queue<int>q;
        for(int i = 0; i < graph.size(); i++){
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

        sort(begin(topo), end(topo));

        return topo;
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();