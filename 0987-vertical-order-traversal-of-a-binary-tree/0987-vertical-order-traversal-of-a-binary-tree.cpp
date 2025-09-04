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
    //1 recursion to find the max right depth and max left depth
    int minc = INT_MAX, maxc = INT_MIN;
    void traverse(TreeNode* root, int cur){
        if(root == nullptr) return;
        minc = min(minc,cur);
        maxc = max(maxc,cur);
        traverse(root->left,cur-1);
        traverse(root->right,cur+1);
    }
     void fill(TreeNode* root, int cur, int row, vector<vector<pair<int,int>>> &ans){
        if(!root) return;
        ans[cur - minc].push_back({row, root->val});
        fill(root->left, cur - 1, row + 1, ans);
        fill(root->right, cur + 1, row + 1, ans);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root,0);
        int cols = maxc - minc + 1;
        vector<vector<int>> ans(cols);
        vector<vector<pair<int,int>>> temp(cols);
        fill(root,0,0,temp);
        for(int i = 0; i < cols; i++){
            sort(temp[i].begin(), temp[i].end()); 
            for(auto &p : temp[i]) ans[i].push_back(p.second);
        }
        return ans;
    }
};