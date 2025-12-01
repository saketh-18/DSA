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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {}; 
        queue<pair<TreeNode*, int>> que;
        que.push({root, 0});

        int row = 0;
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                const auto& [node, col] = que.front();
                que.pop();
                maxIndex = max(col, maxIndex);
                index = min(col, index);
                mat[col].push_back({row, node->val});
                if(node->left){
                    que.push({node->left, col-1});
                }
                if(node->right){
                    que.push({node->right, col+1}); 
                }
            }
            row++;
        }
        if(index < 0) index = -index;
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