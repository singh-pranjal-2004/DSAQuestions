/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int left = 0, right = n-1;
        int top = 0, bottom = m-1;
        vector<vector<int>>ans(m, vector<int>(n, -1));
        ListNode* curr = head;
        while(curr!=NULL){
            
            // top
            for(int i = left; i <= right && curr; i++){
                ans[top][i] = curr -> val;
                curr = curr -> next;
            }
            top++;
            
            // right
            for(int i = top; i <= bottom && curr; i++){
                ans[i][right] = curr -> val;
                curr = curr -> next;
            }
            right--;

            // bottom
            for(int i = right; i >= left && curr; i--){
                ans[bottom][i] = curr -> val;
                curr = curr -> next;
            }
            bottom--;

            // left
            for(int i = bottom; i >= top && curr; i--){
                ans[i][left] = curr -> val;
                curr = curr -> next;
            }
            left++;
        }

        return ans;
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();