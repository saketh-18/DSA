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
    int maxi = 0;
    int mp(TreeNode* root){
        if(root == nullptr) return 0;

        int left = mp(root->left);
        int right = mp(root->right);
        maxi = max(maxi,left+right+root->val);
        return root->val + max(left , right);
    }
    int maxPathSum(TreeNode* root) {
        int temp = mp(root);
        return maxi;
    }
};