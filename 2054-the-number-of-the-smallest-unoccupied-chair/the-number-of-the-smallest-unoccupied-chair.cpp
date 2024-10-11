class Solution {
public:
    typedef pair<int, int>P;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        int find = times[targetFriend][0];
        int chairNum = 0;

        sort(begin(times), end(times));

        priority_queue<P, vector<P>, greater<P>>occupied;
        priority_queue<int, vector<int>, greater<int>>free;

        for(int i = 0; i < n; i++){
            int arrival = times[i][0];
            int departure = times[i][1];
            int ans = chairNum;

            while(!occupied.empty() && occupied.top().first <= arrival){
                free.push(occupied.top().second);
                occupied.pop();
            }

            if(free.empty()) occupied.push({departure, chairNum++});
            else{
                ans = free.top();
                occupied.push({departure, ans});
                free.pop();
            }

            if(arrival == find) return ans;
        }

        return -1;
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();