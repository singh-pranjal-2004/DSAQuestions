/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> v;
        queue<TreeNode*> q;

        if (root)
            q.push(root);

        while (!q.empty()) {
            int ans = 0;
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                ans += curr->val;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            v.push_back(ans);
        }

        TreeNode* ans = new TreeNode(0);
        queue<TreeNode*> qq;
        qq.push(ans);
        q.push(root);
        int idx = 1;

        while (!q.empty()) {
            bool todo = true;
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                int currAns = 0;
                TreeNode* curr = q.front();
                TreeNode* curr2 = qq.front();
                q.pop();
                qq.pop();

                int left = 0, right = 0;

                if (curr->left) {
                    left = curr->left->val;
                    q.push(curr->left);
                }

                if (curr->right) {
                    right = curr->right->val;
                    q.push(curr->right);
                }

                currAns = currAns + left + right;

                if (idx < v.size() && currAns == v[idx])
                    todo = false;

                if (todo) {
                    if (idx < v.size()) {
                        int temp = v[idx] - currAns;
                        if (curr->left) {
                            TreeNode* leftTemp = new TreeNode(temp);
                            curr2->left = leftTemp;
                            qq.push(curr2->left);
                        }

                        if (curr->right) {
                            TreeNode* rightTemp = new TreeNode(temp);
                            curr2->right = rightTemp;
                            qq.push(curr2->right);
                        }
                    }
                } else {
                    if (curr->left) {
                        TreeNode* leftTemp = new TreeNode(0);
                        curr2->left = leftTemp;
                        qq.push(curr2->left);
                    }

                    if (curr->right) {
                        TreeNode* rightTemp = new TreeNode(0);
                        curr2->right = rightTemp;
                        qq.push(curr2->right);
                    }
                }
            }
            idx++;
        }
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