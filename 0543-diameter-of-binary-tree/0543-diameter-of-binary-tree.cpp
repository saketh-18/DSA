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
    int height(TreeNode* root){
        if(root == nullptr) return 0;

        return 1 + max(height(root->left), height(root->right));
    }
    void dia(TreeNode* root, int &maxi){
        if(root == nullptr) return ;
        int l = height(root->left);
        int r = height(root->right);

        maxi = max(maxi, l + r);
        dia(root->right, maxi);
        dia(root->left, maxi);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        dia(root,maxi);
        return maxi;
    }
};