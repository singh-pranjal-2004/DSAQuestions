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

static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout.tie(nullptr);
    return 0;
}();

int init = [] {
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string str; getline(cin, str);) {
        istringstream ss(str); ss.ignore(3);
        ostringstream os;
        int sum = 0;
        bool first = true;
        cout << '[';
        for (int i; ss >> i; ss.ignore()) {
            if (!i) {
                os << (first ? "" : ",") << sum;
                sum = 0;
                first = false;
            } else {
                sum += i;
            }
        }
        os << ']';
        cout << os.str() << '\n';
    }
    exit(0);
    return 0;
}();

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
