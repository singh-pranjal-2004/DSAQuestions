class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(auto adjacent: adj[node]){
                inDegree[adjacent]--;
                if(inDegree[adjacent] == 0) q.push(adjacent);
            }
        }

        return count == numCourses;


    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();