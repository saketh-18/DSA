class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //reverse the graph
        //measure indegree of each node in reversed graph (outdegree)
        //normal topological sort

        //convert incoming into outgoing edges and vice versa

        vector<vector<int>> ng(graph.size() , vector<int>(0));
        for(int i = 0 ; i < graph.size(); i++){
            for(int j = 0 ; j < graph[i].size(); j++){
                ng[graph[i][j]].push_back(i);
            }
        }

        vector<int> id(graph.size());
        for(int i = 0 ; i < ng.size(); i++){
            for(int j = 0 ; j < ng[i].size(); j++){
                id[ng[i][j]]++;
            }
        }

        queue<int> que;
        for(int i = 0 ; i < id.size(); i++){
            if(id[i] == 0) que.push(i);
        }

        while(!que.empty()){
            int node = que.front();
            que.pop();

            for(int i : ng[node]){
                id[i]--;
                if(id[i] == 0) que.push(i);
            }
        }

        vector<int> ans;
        for(int i = 0 ; i < id.size(); i++){
            if(id[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};