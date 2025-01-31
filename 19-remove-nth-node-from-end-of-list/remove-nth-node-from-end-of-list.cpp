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

        if(c == n) {
            ListNode* newHead = head -> next;
            delete head;
            return newHead;
        }

        int res = c - n;

        curr = head;
        while(curr != NULL){
            res--;
            if(res == 0) break;

            curr = curr -> next;
        }

        ListNode* delNode = curr -> next;
        curr -> next = curr -> next -> next;
        delete delNode;

        return head;
    }
};