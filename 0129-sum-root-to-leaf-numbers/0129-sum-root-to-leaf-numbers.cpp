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
    int helper(TreeNode* root , int sum){
        if(root == nullptr) return 0;
        if(root-> left == nullptr && root->right == nullptr) return sum + root->val;

        int left = helper(root->left , (sum+root->val)*10);
        int right = helper(root->right , (sum+root->val)*10);
        return left + right;
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        sum = helper(root , sum);
        return sum;
    }
};