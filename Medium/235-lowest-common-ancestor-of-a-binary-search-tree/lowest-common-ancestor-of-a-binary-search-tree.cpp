/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;

        int curr = root->val, pp = p->val, qq = q->val;
        if(curr<pp && curr<qq){
            return lowestCommonAncestor(root->right, p, q);
        }
        if(curr>pp && curr>qq){
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};
