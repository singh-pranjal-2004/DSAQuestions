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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;

        int c = 0;
        ListNode* curr = head;
        while(curr != NULL) {
            c++;
            curr = curr -> next;
        }

        c = c - n;
        if(c < 0) return NULL;
        if(c == 0) return head->next;

        curr = head;
        ListNode* prev = NULL;
        while(c--){
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;
        delete curr;

        return head;
    }
};