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
    TreeNode* deleter(TreeNode* root, vector<TreeNode*>& result, unordered_set<int>& st){
        if(root == NULL) return NULL;

        root -> left = deleter(root->left, result, st);
        root -> right = deleter(root->right, result, st);

        if(st.find(root->val) != st.end()){
            if(root->left != NULL) result.push_back(root->left);
            if(root->right != NULL) result.push_back(root->right);
            return NULL;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        unordered_set<int> st;

        for(auto i: to_delete){
            st.insert(i);
        }

        deleter(root, result, st);

        if(st.find(root->val) == st.end()){
            result.push_back(root);
        }

        return result;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();