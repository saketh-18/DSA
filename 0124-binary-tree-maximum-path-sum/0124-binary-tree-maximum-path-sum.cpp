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
    int maxi = -1e9;
    int path(TreeNode *root){
        if(root == nullptr) return 0;

        int l = path(root->left);
        int r = path(root->right);

        int l_or_r = max(l,r) + root->val;
        int only_root = root->val;
        int both_l_and_r = l + r + root->val;
        maxi = max({maxi, l_or_r, only_root, both_l_and_r});
        return max(only_root,l_or_r);
    }
    int maxPathSum(TreeNode* root) {
        int temp = path(root);
        return maxi;
    }
};