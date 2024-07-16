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
private:
    TreeNode* LCA(TreeNode* root, int p, int q){
        if(root == NULL) return NULL;

        if(root -> val == p || root -> val == q) return root;

        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);

        if(left == NULL && right == NULL) return NULL;
        else if(left == NULL && right != NULL) return right;
        else if(left != NULL && right == NULL) return left;
        else return root;
    }

    bool route(TreeNode* root, int value, string& str){
        if(root == NULL) return false;

        if(root->val == value) return true;

        str.push_back('L');
        bool leftMila = route(root->left, value, str);
        if(leftMila){
            return true;
        }
        str.pop_back();

        str.push_back('R');
        bool rightMila = route(root->right, value, str);
        if(rightMila){
            return true;
        }
        str.pop_back();

        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = LCA(root, startValue, destValue);

        string leftStr = "", rightStr = "";
        route(lca, startValue, leftStr);
        route(lca, destValue, rightStr);

        string result = "";
        for(auto s: leftStr){
            result.push_back('U');
        }
        result += rightStr;

        return result;

    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();