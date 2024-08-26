/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void postOrderTraversal(Node* root, vector<int>& ans){
        if(!root) return;

        for(auto i: root->children){
            postOrderTraversal(i, ans);
        }

        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;
        postOrderTraversal(root, ans);

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