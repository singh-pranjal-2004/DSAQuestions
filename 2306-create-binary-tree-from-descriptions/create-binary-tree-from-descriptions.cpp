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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*>mp;
        unordered_set<int> childSet;

        for(auto& desc : descriptions){
            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];

            childSet.insert(child);

            if(mp.find(parent) == mp.end()){
                TreeNode* parentNode = new TreeNode(parent);
                mp[parent] = parentNode;
            }

            if(mp.find(child) == mp.end()){
                TreeNode* childNode = new TreeNode(child);
                mp[child] = childNode;
            }

            if(isLeft){
                mp[parent] -> left = mp[child];
            }else{
                mp[parent] -> right = mp[child];
            }
        }

        for(auto& m: mp){
            if(childSet.find(m.first) == childSet.end()) return m.second;
        }

        return NULL;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();