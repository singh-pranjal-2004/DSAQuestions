class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));

        int n1 = nums1.size(), n2 = nums2.size();

        vector<vector<int>> ans;

        int i = 0, j = 0;
        while(i < n1 && j < n2) {
            vector<int>temp;
            if(nums1[i][0] == nums2[j][0]) {
                int sum = nums1[i][1] + nums2[j][1];
                temp.push_back(nums1[i][0]);
                temp.push_back(sum);

                ans.push_back(temp);
                i++;
                j++;
            } else if(nums1[i][0] < nums2[j][0]) {
                temp.push_back(nums1[i][0]);
                temp.push_back(nums1[i][1]);
                ans.push_back(temp);
                i++;
            } else {
                temp.push_back(nums2[j][0]);
                temp.push_back(nums2[j][1]);
                ans.push_back(temp);
                j++;
            }
        }

        while(i < n1) {
            vector<int>temp;
            temp.push_back(nums1[i][0]);
            temp.push_back(nums1[i][1]);
            ans.push_back(temp);
            i++;
        }

        while(j < n2) {
            vector<int>temp;
            temp.push_back(nums2[j][0]);
            temp.push_back(nums2[j][1]);
            ans.push_back(temp);
            j++;
        }

        return ans;
    }
};