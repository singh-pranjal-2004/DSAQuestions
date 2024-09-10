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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL) return head;

        ListNode* dummy = head;
        ListNode* prev = dummy;
        ListNode* curr = dummy -> next;

        while(curr){
            int g = gcd(prev->val, curr->val);

            ListNode* gc = new ListNode();
            gc->val = g;
            gc->next = curr;
            prev->next = gc;

            prev = curr;
            curr = curr->next;
        }

        return dummy;
    }
};