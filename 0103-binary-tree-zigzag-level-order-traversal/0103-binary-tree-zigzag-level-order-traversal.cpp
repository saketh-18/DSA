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
        que.push(root);

        vector<vector<int>> ans;

        int flag = 0;
        while(!que.empty()){
            int size = que.size();
            vector<int> temp(size,0);

            int i = 0;
            size--;
            while(!que.empty() && i <= size){
                TreeNode* node = que.front();
                que.pop();

                if(flag == 1){
                    temp[size-i] = node->val;
                } else temp[i] = node->val;

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                i++;
            }
            ans.push_back(temp);
            flag = 1-flag;
        }
        return ans;
    }
};