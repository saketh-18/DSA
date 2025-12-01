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
    unordered_map<int,vector<pair<int,int>>> mat;
    int index = 0, maxIndex = 0;
    void dfs(TreeNode* root, int col, int row){
        if(!root) return ;
        index = min(index, col);
        maxIndex = max(maxIndex, col);
        mat[col].push_back({row,root->val});
        dfs(root->left, col-1, row+1);
        dfs(root->right, col+1, row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // traverse the whole tree and find the number of columns
        dfs(root,0,0);
        cout << maxIndex << "  " << index << endl;
        if(index < 0){
            index = -index;
        }
        vector<vector<int>> ans(maxIndex + index + 1);
        for(auto &pos : mat){
            // cout << "row " << pos.first << " ";
            sort(pos.second.begin(), pos.second.end(), [&](pair<int,int> &a, pair<int,int> &b){
                if(a.first == b.first){
                    return a.second < b.second;
                }
                return a.first < b.first;
            });
            for(pair<int,int> i : pos.second){
                // cout << i << " ";
                cout << pos.first << " " << index << endl;
                ans[pos.first + index].push_back(i.second);
            }
            // cout << endl;
        }
        return ans;
    }
};