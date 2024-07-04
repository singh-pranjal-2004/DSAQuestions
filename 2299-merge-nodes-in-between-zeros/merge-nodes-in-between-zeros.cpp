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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode();
        ListNode* curr = ans;

        head = head->next;
        int sum = 0;
        while(head!=NULL){
            if(head->val == 0){
                curr->next = new ListNode(sum);
                curr = curr->next;
                sum = 0;
            }

            sum+=head->val;
            head = head->next;
        }

        return ans->next;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();