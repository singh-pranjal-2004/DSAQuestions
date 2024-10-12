class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));

        priority_queue<int, vector<int>, greater<int>> ans;

        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(ans.empty()) ans.push(end);
            else{
                int minEnd = ans.top();
                if(start > minEnd){
                    ans.pop();
                }

                ans.push(end);
            }
        }

        return ans.size();
    }
};