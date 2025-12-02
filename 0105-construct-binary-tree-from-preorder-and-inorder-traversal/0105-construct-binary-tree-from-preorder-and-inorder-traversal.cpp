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
    map<int,int> inmap;
    TreeNode* build(vector<int> &inorder, vector<int> &preorder, int instart, int inend, int prestart, int preend){
        if (instart > inend || prestart > preend) return nullptr;

        TreeNode* root = new TreeNode(preorder[prestart]);
        //find the root in inorder
        int inel = inmap[preorder[prestart]];

        int left_size = inel - instart;
        TreeNode* left =  build(inorder,preorder,instart,inel-1,prestart + 1,prestart + left_size);
        TreeNode* right = build(inorder, preorder, inel + 1, inend,prestart + left_size + 1, preend);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0;i < inorder.size(); i++){
            inmap[inorder[i]] = i;
        }
        return build(inorder,preorder,0,inorder.size()-1,0, preorder.size() - 1);
    }
};