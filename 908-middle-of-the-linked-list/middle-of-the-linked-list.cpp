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
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* curr = head;
        while(curr){
            count++;
            curr = curr -> next;
        }

        int aC = count / 2;
        curr = head;
        while(aC != 0) {
            aC--;
            curr = curr -> next;
        }

        return curr;
    }
};