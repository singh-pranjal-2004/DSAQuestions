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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long>pq;

        queue<TreeNode*>q;
        if(root) q.push(root);

        while(!q.empty()){
            long long ans = 0;
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++){
                TreeNode* currentNode = q.front();
                q.pop();
                ans += currentNode->val;

                if(currentNode->left != NULL) q.push(currentNode->left);
                if(currentNode->right != NULL) q.push(currentNode->right);
            }

            pq.push(ans);
        }

        if(k > pq.size()) return -1;
        
        k--;
        while(!pq.empty() && k--){
            pq.pop();
        }

        return pq.top();
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();