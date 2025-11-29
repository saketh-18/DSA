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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> que;
        vector<vector<int>> ans;
        que.push(root);

        while(!que.empty()){
            int size = que.size();

            vector<int> temp;
            for(int i = 0; i < size; i++){
                TreeNode* curr = que.front();
                temp.push_back(curr->val);
                if(curr->left){
                    que.push(curr->left);
                } 
                if(curr->right){
                    que.push(curr->right);
                }
                que.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};