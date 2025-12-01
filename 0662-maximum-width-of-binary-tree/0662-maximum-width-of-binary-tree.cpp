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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<tuple<TreeNode*,unsigned long long, unsigned long long>> que;
        que.push({root,1,0}); // Node, value of node(accr. to heap tree), level
        unsigned long long prevLevel = 0, prevNum = 1;
        // creating a sort of heap tree and then computing max nodes in every level and getting the max 
        unsigned long long res = 0;
        while(!que.empty()){
            auto [node, val, level] = que.front();
            que.pop();

            if(level > prevLevel){  //this will execute at the start of every level except first (0th)
                prevLevel = level;
                prevNum = val;
            }

            res = max(res, val - prevNum + 1);
            
            if(node->left){
                que.push({node->left, val*2, level+1});
            }
            if(node->right){
                que.push({node->right, val*2 + 1, level + 1});
            }
        }
        return res;
    }
};