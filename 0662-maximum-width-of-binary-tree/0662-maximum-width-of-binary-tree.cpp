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
        long long maxSum = 0;
        queue<pair<TreeNode* , long long>> q;
        q.push({root , 0});

        while(!q.empty()){
            int size = q.size();
            long long sIndex = q.front().second;
            long long eIndex = q.back().second;
            long long diff = eIndex - sIndex + 1;
            maxSum = max(maxSum , diff);

            for(int i = 0 ; i < size; i++){
                pair<TreeNode* , long long> current = q.front();
                q.pop();
                long long normIndex = current.second - sIndex;
                if(current.first->left){
                    q.push({current.first->left , 2*normIndex}); 
                }
                if(current.first->right){
                    q.push({current.first->right , 2*normIndex + 1}); 
                }
            }
        }
        return (int)maxSum;
    }
};