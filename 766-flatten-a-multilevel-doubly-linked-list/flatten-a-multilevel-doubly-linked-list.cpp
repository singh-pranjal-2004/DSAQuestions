/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void bandan(Node* head, Node* last){
        Node* temp = head -> next;
        head -> next = head -> child;
        head -> child -> prev = head;
        head -> child = NULL;
        last -> next = temp;
        if(temp != NULL) temp -> prev = last;
    }

    Node* dfs(Node* head){
        if(head -> next == NULL && head -> child == NULL) return head;
        if(head -> child == NULL) return dfs(head -> next);

        Node* last = dfs(head -> child);
        bandan(head, last);
        return dfs(last);
    }

    Node* flatten(Node* head) {
        if(head == NULL) return NULL;

        dfs(head);

        return head;
    }
};