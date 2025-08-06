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
    vector<int> rightSideView(TreeNode* root) {
       //bfs
       if(root == nullptr) return {};
       queue<TreeNode*> que; 
       que.push(root);
        vector<vector<int>> vec;
        vec.push_back({root->val});
       while(!que.empty()){
        vector<int> tem;
        int size = que.size();
        for(int i = 0 ;i < size; i++){
            TreeNode* temp = que.front();
            que.pop();
            if(temp->left){
                 tem.push_back(temp->left->val); 
                 que.push(temp->left);
                 }
            if(temp->right){
                 tem.push_back(temp->right->val); 
                 que.push(temp->right);
                 }
        }
        
        if(tem.size() > 0) vec.push_back(tem);
       }
       vector<int> ans;
       for(int i = 0 ; i < vec.size(); i++){
        ans.push_back(vec[i][vec[i].size()-1]);
       }
       return ans;
    }
};