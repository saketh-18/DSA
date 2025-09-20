class Solution {
public:
    void topo(int i, vector<int> &vis, vector<vector<int>> &adj, int parent){
        vis[i] = 1;
        for(int course : adj[i]){
            if(vis[course] == 1) return;
            if(vis[course] == 0){
                topo(course, vis, adj, i);
            }
        }
        vis[i] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        //make an adjacency list out of the given prerequisites.
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        //just do topo sort;
        vector<int> vis(numCourses);
        for(int i = 0 ; i < numCourses; i++){
            if(vis[i] == 0){
                topo(i, vis, adj, -1);
            }
        }

    //    return topo(0,vis,adj,-1);

        int count = 0;
        for(int i : vis){
            i == 2 ? count++ : count = count;
        }
        return count == numCourses;
    }

};