class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build the adjacency list 
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        // Step 2: Calculate in-degrees 
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i])
                indegree[it]++;
        }

        // Step 3: Push all courses with 0 prerequisites into the queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 4: Perform BFS (Topological Sort) to determine a valid order
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);  // This course can now be taken

            // Reduce the in-degree of all dependent courses
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);  // This course is now ready to be taken
                }
            }
        }

        // Step 5: If we managed to take all courses, return the order
        if (topo.size() == numCourses) return topo;

        // Otherwise, there's a cycle (some courses can't be completed)
        return {};
    }
};