class Solution {
public:
    vector<int> findOrder(int nums, vector<vector<int>>& pre) {
        //create an adjacency list 
        //use kahn's algo
        //return topo array if topo.size() == nums
        //else return empty array

        vector<vector<int>> adj(nums);
        vector<int> id(nums);
        for(int i = 0 ; i < pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            id[pre[i][0]]++;
        }

        queue<int> que;
        vector<int> topo;

        for(int i = 0; i < nums;i++){
            if(id[i] == 0){
                que.push(i);
            }
        }

        if(que.empty()) return {};

        while(!que.empty()){
            int node = que.front();
            que.pop();
            topo.push_back(node);

            for(int i : adj[node]){
                id[i]--;
                if(id[i] == 0) que.push(i);
            }
        }

        if(topo.size() == nums) return topo;
        else return {};
    }
};