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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        stack<TreeNode*> st;
        stack<int> ans;
        vector<int> vec;

        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();

            ans.push(curr->val);
            if(curr->left != nullptr){
                st.push(curr->left);
            }

            if(curr->right != nullptr){
                st.push(curr->right);
            }


        }

        while(!ans.empty()){    
            vec.push_back(ans.top());
            ans.pop();
        }

        return vec;
    }
};