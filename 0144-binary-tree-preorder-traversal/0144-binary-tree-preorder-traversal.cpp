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
    vector<int> preorderTraversal(TreeNode* root) {
    // take a stack
    // add root to stack , 
    // loop -->
    // remove last element from stack and print
    // add right element and left element on to stack
    // end loop when stack is empty

    
    vector<int> ans;
    if(root == nullptr){
        return ans;
    }
    stack<TreeNode*> pre;
    pre.push(root);
    while(!pre.empty()){
        TreeNode* temp = pre.top();
        ans.push_back(temp->val);
        pre.pop();

        if(temp->right != nullptr){
            pre.push(temp->right);
        }

        if(temp->left != nullptr){
            pre.push(temp->left);
        }
    }

    return ans;

    }
};