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
    void preorder(TreeNode* root , vector<TreeNode*> &res){
        if(root == nullptr) return;

        res.push_back(root);
        preorder(root->left , res);
        preorder(root->right, res);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> res;
        preorder(root , res);

        for(int i = 1; i < res.size(); i++){
            root->left = nullptr;
            root->right = res[i];
            root = root->right;
        }
    }
};