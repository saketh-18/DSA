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
    int path(TreeNode* root , int &maxSum){
        if(root == nullptr) return 0;

        int leftSum = path(root->left , maxSum);
        int rightSum = path(root->right , maxSum);

        int nodeSum = max(max(root->val , root->val + leftSum + rightSum) , max(root->val + leftSum, root->val + rightSum));
        maxSum = max(nodeSum , maxSum);
        return max(root->val , max(root->val + rightSum , root->val + leftSum));
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = root->val;
        path(root , maxSum);
        return maxSum;
    }
};