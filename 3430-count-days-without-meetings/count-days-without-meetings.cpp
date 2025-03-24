class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));

        int count = 0;
        int s = 0;
        int e = 0;

        for(auto& meet: meetings) {
            if(meet[0] > e) {
                count += meet[0] - e - 1;
            }

            e = max(e, meet[1]);
        }

        if(days > e) {
            count += days - e;
        }

        return count;
    }
};