class Solution {
public:
    bool dfs(int node , int color , vector<int> &vis , vector<vector<int>> &graph){
        vis[node] = color;

        for(int i : graph[node]){
            if(vis[i] == color) return false;
            else if(vis[i] == -1 && !dfs(i , 1-color , vis , graph)){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        //color all the nodes in the graph in two colours
        //no adjacent nodes should have the same colour
        //if every node is coloured , then the graph is bipartite;

        vector<int> vis(graph.size() , -1);
        for(int i = 0 ; i < vis.size(); i++){
            if(vis[i] == -1){
                if (dfs(i , 0 , vis , graph) == false) {
                    return false;
                }
            }
        }

        return true;

    }
};