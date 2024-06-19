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
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root->left == NULL && root->right==NULL){
            return true;
        }

        long long min = -1000000000000, max = 1000000000000;
        return isValidBST(root, min, max);
    }

    bool isValidBST(TreeNode* root, long long min, long long max){
        if(root==NULL) return true;

        if(root->val > min && root->val < max){
            bool left = isValidBST(root->left, min, root->val);
            bool right = isValidBST(root->right, root->val, max);
            return left && right;
        }
        else{
            return false;
        }
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();