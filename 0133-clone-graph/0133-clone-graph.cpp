/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node , vector<Node*> &list , Node* clone){
        
        for(Node* i : node->neighbors){
            if(clone->neighbors.size() == node->neighbors.size()) break;
            if(!list[i->val]){
                Node* temp =  new Node(i->val);
                list[i->val] = temp;
                clone->neighbors.push_back(temp);
                dfs(i, list, temp);
            } else {
                clone->neighbors.push_back(list[i->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        //create a copy of first node
        vector<Node*> store(101);
        // vector<int> vis(100);
        if(node){
            Node* ans = new Node(node->val);
            store[node->val] = ans;
            dfs(node, store, ans);
            return ans; 
        } else return nullptr;
    }
};