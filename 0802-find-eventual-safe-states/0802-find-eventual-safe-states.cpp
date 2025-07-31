class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        // Base cases
        if (state[node] == 1) return false;  // already visiting → cycle detected
        if (state[node] == 2) return true;   // already marked safe

        // Mark as visiting (currently in path)
        state[node] = 1;

        for (int neighbor : graph[node]) {
            if(state[neighbor] == 1) return false;
            if (state[neighbor] == 0) {
                // If any neighbor is unsafe, then this node is unsafe
                if(!dfs(neighbor , graph , state)){
                return false;
                }
            }
        }

        // Mark as safe
        state[node] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);  // 0: unvisited, 1: visiting, 2: safe
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, state)) {
                result.push_back(i);
            }
        }

        return result;
    }
};
