/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    unordered_set<int>st;
    void restoreTree(TreeNode* root) {
        if(root == NULL)
            return;
        
        if(root -> val == -1)
            root -> val = 0;

        st.insert(root -> val);

        if(root -> left) {
            root -> left -> val = 2 * root -> val + 1;
            restoreTree(root -> left); 
        }

        if(root -> right) {
            root -> right -> val = 2 * root -> val + 2;
            restoreTree(root -> right);
        }
    }

    FindElements(TreeNode* root) {
        restoreTree(root);
    }
    
    bool find(int target) {
        return st.find(target) != st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */