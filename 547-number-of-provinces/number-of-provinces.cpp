class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& vis){
        vis[node] = 1;
        for(auto it: adjList[node]){
            if(!vis[it]){
                dfs(it, adjList, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<vector<int>> adjList(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count++;
                dfs(i, adjList, vis);
            }
        }

        return count;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();