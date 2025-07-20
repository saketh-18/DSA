class Solution {
public:
    bool dfs(int node , int color , vector<vector<int>> &graph , vector<int> &vis){
        vis[node] = color;

        for(int neighbor : graph[node]){
            if(vis[neighbor] == color) return false;
            if(vis[neighbor] == -1){
                if(dfs(neighbor , 1-color , graph , vis) == false){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size() , -1);
        for(int i = 0 ; i < vis.size(); i++){
            if(vis[i] == -1){
                if(dfs(i , 0 , graph , vis) == false){
                    return false;
                }
            }
        }
        return true;
    }
};