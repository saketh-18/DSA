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
    bool check(TreeNode* root, TreeNode* root2){
        if(root && root2){
            if(root->val == root2->val){
                return check(root->left,root2->left) && check(root->right,root2->right);
            } else return false;
        } else if(root == nullptr && root2 == nullptr) return true;
        return false;
    }
    void find(TreeNode* root, TreeNode* sub, vector<TreeNode*> &list){
        if(root == nullptr) return ;

        if(root->val == sub->val) list.push_back(root);
        find(root->left,sub,list);
        find(root->right,sub,list);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<TreeNode*> same;
        find(root,subRoot,same);

        for(auto node : same){
            if(check(node,subRoot)){
                return true;
            }
        }
        return false;
    }
};