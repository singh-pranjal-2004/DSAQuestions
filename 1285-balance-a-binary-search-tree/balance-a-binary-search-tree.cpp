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
    void storer(vector<TreeNode*>& vect, TreeNode* root){
        if(!root) return;

        storer(vect, root->left);
        vect.push_back(root);
        storer(vect, root->right);
    }

    TreeNode* solver(vector<TreeNode*> vect, int start, int end){
        if(start > end) return NULL;

        int mid = (end - start)/2+start;

        TreeNode* root = vect[mid];
        root->left = solver(vect, start, mid-1);
        root->right = solver(vect, mid+1, end);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> vect;
        storer(vect, root);
        return solver(vect, 0, vect.size()-1);
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();


