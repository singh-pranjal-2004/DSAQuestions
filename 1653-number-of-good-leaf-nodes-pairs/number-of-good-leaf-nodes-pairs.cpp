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
    void makeGraph(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& adj, unordered_set<TreeNode*>& st, TreeNode* prev){
        if(!root) return;

        if(root->left == NULL && root->right == NULL) st.insert(root);

        if(prev != NULL){
            adj[prev].push_back(root);
            adj[root].push_back(prev);
        }

        makeGraph(root->left, adj, st, root);
        makeGraph(root->right, adj, st, root);
    }

    int bfs(TreeNode* leaf, unordered_map<TreeNode*, vector<TreeNode*>>& adj, unordered_set<TreeNode*>& st, int distance){
        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;
        q.push(leaf);
        vis.insert(leaf);

        int count = 0;
        for(int lvl = 0; lvl <= distance; lvl++){
            int size = q.size();
            while(size--){
                TreeNode* curr = q.front();
                q.pop();

                if(curr != leaf && st.find(curr) != st.end()) count++;

                for(auto& it: adj[curr]){
                    if(vis.find(it) == vis.end()){
                        q.push(it);
                        vis.insert(it);
                    }
                }
            }
        }

        return count;            
    }
public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj; // Graph
        unordered_set<TreeNode*> st; // Leaf Nodes

        makeGraph(root, adj, st, NULL); // NULL for previous node as root dont have prev node so null
        int cnt = 0;
        for(auto& leaf: st){
            cnt += bfs(leaf, adj, st, distance);
        }

        return cnt/2;
    }
};