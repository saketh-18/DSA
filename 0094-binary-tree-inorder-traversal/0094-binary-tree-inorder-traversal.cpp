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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        stack<TreeNode*> dfs;
        vector<int> ans;
        TreeNode* curr = root;

        while(curr != nullptr || !dfs.empty()){

            while(curr != nullptr){
                dfs.push(curr);
                curr = curr->left; 
            }

            curr = dfs.top();
            dfs.pop();
            ans.push_back(curr->val);

            curr = curr->right;
        }
        return ans;
    }
};