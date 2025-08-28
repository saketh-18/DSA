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
        if (root == nullptr) return 0;
        return max(height(root->left)+1,height(root->right)+1);
    }
    bool check(TreeNode* root){
        if(root == nullptr) return true;
        
        int left = height(root->left);
        int right = height(root->right);

        if(abs(left-right) == 1 || abs(left-right) == 0){
            return check(root->left) && check(root->right); 
        }
        return false; 
    }
    bool isBalanced(TreeNode* root) {
        return check(root);
    }
};