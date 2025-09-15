class Solution {
public:
    void dfs(int node , vector<int> &visited , vector<vector<int>> &graph){
        visited[node] = 1;

        for(int i = 0 ; i < graph.size(); i++){
            if(graph[node][i] == 1 && visited[i] == 0){
                dfs(i , visited , graph);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size() , 0);
        int province = 0;
        for(int i = 0 ; i < vis.size(); i++){
            if(vis[i] == 0) {
                dfs(i , vis , isConnected);
                province++;
            }
        }
        return province;
    }
};