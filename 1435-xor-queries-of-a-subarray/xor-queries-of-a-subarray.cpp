class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<int>xori(arr.size());
        xori[0] = arr[0];
        for(int i = 1; i < arr.size(); i++){
            xori[i] = xori[i-1] ^ arr[i];
        }

        for(int i = 0; i < queries.size(); i++){
            int left = queries[i][0];
            int right = queries[i][1];


            if(left == 0) ans.push_back(xori[right]);
            else{
                ans.push_back(xori[right] ^ xori[left - 1]);
            }
        }
        return ans;

    }
};