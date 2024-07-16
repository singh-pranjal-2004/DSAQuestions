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
        string leftStr = "", rightStr = "";
        route(root, startValue, leftStr);
        route(root, destValue, rightStr);

        int index = 0;
        while(index < leftStr.length() && index < rightStr.length()){
            if(leftStr[index] != rightStr[index]) break;
            index++;
        }

        string result = "";
        for(int i = index; i < leftStr.length(); i++){
            result.push_back('U');
        }
        for(int i = index; i < rightStr.length(); i++){
            result.push_back(rightStr[i]);
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