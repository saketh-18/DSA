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
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* current = root;
        
        while(current != nullptr || !st.empty()){
            while(current != nullptr){
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();
            ans.push_back(current->val);


            current = current->right;

        }
        return ans;
    }
};