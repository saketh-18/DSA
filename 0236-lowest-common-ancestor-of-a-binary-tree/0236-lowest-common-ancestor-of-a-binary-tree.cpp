/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> ans;
    void ancestor(TreeNode* root, TreeNode* anc){
        if(root == nullptr) return;

        ans[root] = anc;
        ancestor(root->left,root);
        ancestor(root->right,root);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        ancestor(root,nullptr);
        if(ans[p] == ans[q]) return ans[p];
        unordered_map<TreeNode* , TreeNode*> right;
        vector<pair<TreeNode*,TreeNode*>> left;
        
        TreeNode* temp = p;
        TreeNode* temp2 = q;
        while(ans[temp] != nullptr){
            left.push_back({temp,ans[temp]});
            temp = ans[temp];
        }
        while(ans[temp2] != nullptr){
            right[temp2] = ans[temp2];
            temp2 = ans[temp2];
        }
        
        for(const auto& pair : left){
            if(right.find(pair.first) != right.end()) return pair.first;
        }
        return root;
    }
};