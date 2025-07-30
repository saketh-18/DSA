class Solution {
public:
    bool canFinish(int nums, vector<vector<int>>& pre) {
        //create an adjacency list
        //created indegree array
        //create topo array

        //adjacency list
        vector<vector<int>> adj(nums);
        vector<int> id(nums);
        for(int i = 0 ; i < pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            id[pre[i][0]]++;
        }

        queue<int> que;
        for(int i = 0 ; i < nums;i++){
            if(id[i] == 0){
                que.push(i);
            }
        }

        // if(que.size() == 0) return true;
        vector<int> topo;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            topo.push_back(node);

            for(int i : adj[node]){
                id[i]--;
                // if(id[i] < 0) return true;
                if(id[i] == 0) que.push(i);
            }
        }
        return topo.size() == nums;
    }
};