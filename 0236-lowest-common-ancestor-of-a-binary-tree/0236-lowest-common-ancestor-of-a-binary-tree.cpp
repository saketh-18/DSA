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
    void search(TreeNode* root, TreeNode* p, TreeNode* q, bool &vis_p, bool &vis_q){
        if(!root) return;

        if(root == p) vis_p = true;
        if(root == q) vis_q = true;
        if(vis_p && vis_q) return ;
        search(root->left, p, q, vis_p, vis_q);
        search(root->right, p, q, vis_p, vis_q);
    }
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return nullptr;
        bool a = false, b = false;
        if(root == p) a = true;
        if(root == q) b = true;
        if(a || b){
            return root;
        }
        search(root->left, p, q, a, b);
        if(a && b){
            return dfs(root->left, p, q);
        }
        if(a || b) return root;
        return dfs(root->right, p, q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        return dfs(root, p, q);
    }
};