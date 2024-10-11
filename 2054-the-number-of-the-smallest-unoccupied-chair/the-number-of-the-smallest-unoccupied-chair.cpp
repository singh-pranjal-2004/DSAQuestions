class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int find = times[targetFriend][0];
        sort(times.begin(), times.end());
        int n = times.size();
        vector<int>chairs(n, -1);

        for(int i = 0; i < n; i++){
            int arrival = times[i][0];
            int departure = times[i][1];

            int k;
            for(k = 0; k < n; k++){
                if(chairs[k] == -1 || chairs[k] <= arrival){
                    chairs[k] = departure;
                    if(arrival == find) return k;
                    break;
                }
            }
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