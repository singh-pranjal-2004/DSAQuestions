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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* evenHead = new ListNode(-1), *evenTail = evenHead;
        ListNode* oddHead = new ListNode(-1), *oddTail = oddHead;
        bool append = true;

        ListNode* curr = head, *temp;
        while(curr != NULL) {
            temp = curr;
            curr = curr -> next;
            temp -> next = NULL;

            if(append){
                evenTail->next = temp;
                evenTail = evenTail -> next;
                append = false;
            } 
            else {
                oddTail->next = temp;
                oddTail = oddTail -> next;
                append = true;
            }
        }

        evenTail->next = oddHead->next;

        return evenHead->next;
    }
};