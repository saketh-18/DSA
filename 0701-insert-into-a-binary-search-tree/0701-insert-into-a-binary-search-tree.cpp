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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if(root == nullptr) return newNode;
        if(root->left == nullptr && root->right == nullptr){
            if(root->val > val){    
                root->left = newNode;
            } 
            else {
                root->right = newNode;
            }
        }
        TreeNode* temp = root;
        TreeNode* back = temp;
        while(temp != nullptr){
            if(temp->val > val){
                back = temp;
                temp = temp->left;
            }
            else {
                back = temp;
                temp = temp->right;
            }
        }
        if(back->val > val){    
            back->left = newNode;
        } 
        else {
            back->right = newNode;
        }
        return root;
    }
};