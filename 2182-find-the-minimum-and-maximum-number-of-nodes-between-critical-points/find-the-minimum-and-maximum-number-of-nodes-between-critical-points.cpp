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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        vector<int> answer;

        if(!head->next || !head->next->next){
            return {-1, -1};
        }

        ListNode* mid = head->next;
        ListNode* end = head->next->next;
        int i = 2;
        while(end!=NULL){
            if(mid->val < head->val && mid->val < end->val) ans.push_back(i);
            else if(mid->val > head->val && mid->val > end->val) ans.push_back(i);

            head = head->next;
            mid = mid->next;
            end = end->next;
            i++;
        }

        int n = ans.size()-1;
        if(n>=1){
            // answer.push_back(ans[n]-ans[n-1]);
            // answer.push_back(ans[n]-ans[0]);
            int mini = ans[n] - ans[n-1];
            // int maxi = ans[n]-ans[0];
            for(int i = n-1; i > 0; i--){
                mini = min(mini, ans[i]-ans[i-1]);
            }
            answer.push_back(mini);
            answer.push_back(ans[n]-ans[0]);
        }else{
            return {-1, -1};
        }
        
        return answer;
    }
};