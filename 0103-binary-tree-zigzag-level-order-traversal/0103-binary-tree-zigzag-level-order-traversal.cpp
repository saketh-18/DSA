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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> que;
        vector<vector<int>> ans;

        que.push(root);

        while(!que.empty()){
            int size = que.size();
            vector<int> temp;

            for(int i = 0;i < size; i++){
                TreeNode* temp_node = que.front();
                que.pop();
                temp.push_back(temp_node->val);
                if(temp_node->left){
                    que.push(temp_node->left);
                } 
                if(temp_node->right){
                    que.push(temp_node->right);
                }
            }
            ans.push_back(temp);
        }
        int flag = 0;
        for(int i = 0; i < ans.size(); i++){
            if(flag == 1){
                reverse(ans[i].begin(), ans[i].end());
                flag = 0;
            } else {
                flag = 1;
            }
        }
        return ans;
    }
};