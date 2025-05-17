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
    int depth(TreeNode* root , int count){
        if(root->left == nullptr && root->right != nullptr){
            return depth(root->right , count + 1);
        }
        else if(root->left != nullptr && root->right == nullptr){
            return depth(root->left , count+1);
        }  
        else if(root->left != nullptr && root->right != nullptr){
            return max(depth(root->left , count + 1) , depth(root->right , count + 1));
        }
        else {
            return count;
        }
    }
    int maxDepth(TreeNode* root) { 
        if(root != nullptr){
            return depth(root , 1);
        }
        else {
            return 0;
        }
    }
};