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
    int getCount(ListNode* head){
        if(head == NULL) return 0;

        return 1 + getCount(head -> next);
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = getCount(head);
        vector<ListNode*>ans(k, NULL);

        int l = count / k;
        int rl = count % k;
        ListNode* curr = head;

        for(int i = 0; i < k && curr; i++){
            ans[i] = curr;

            int currentSize = l;
            if(rl > 0){
                currentSize++;
                rl--;
            }

            for(int j = 1; j < currentSize; j++){
                curr = curr->next;
            }

            ListNode* temp = curr -> next;
            curr -> next = NULL;
            curr = temp;
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