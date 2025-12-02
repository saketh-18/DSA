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
    int countNodes(TreeNode* root){
        if(!root) return 0;

        int left = findHeightLeft(root->left);
        int right = findHeightRight(root->right);

        if(left == right) return (1<<left + 1)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);

    }
    int findHeightLeft(TreeNode* root){
        int i = 0;
        while(root){
            i++;
            root = root->left;
        }
        return i;
    }
    int findHeightRight(TreeNode* root){
        int i = 0;
        while(root){
            i++;
            root = root->right;
        }
        return i;
    }
};