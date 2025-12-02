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
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<int,int> vis;
    void dfs(TreeNode* root, TreeNode* par){
        if(root == nullptr) return;
        parent[root] = par;

        dfs(root->left, root);
        dfs(root->right, root);
    }
    void nodes(TreeNode* root, int k, vector<int> &res, TreeNode* cameFrom){
        if(!root || k < 0) return ;

        if(k == 0 && vis[root->val] == 0){
            res.push_back(root->val);
            return;
        }
        vis[root->val]++;
        nodes(root->left,k-1,res, root);
        nodes(root->right,k-1,res,root);
        TreeNode* par = parent[root];
        if(par && par != cameFrom){
            cout << par->val << endl;
            nodes(par,k-1,res,root); 
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root || !target) return {};
        dfs(root,nullptr);
        vector<int> res;
        nodes(target,k,res,nullptr);
        return res;
    }
};