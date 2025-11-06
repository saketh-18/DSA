class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<int>& vis,
             set<int>& temp) {
        vis[i] = 1;

        for (int j : adj[i]) {
            if (vis[j] == 0) {
                temp.insert(j);
                dfs(j, adj, vis, temp);
            }
        }
        return;
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        // create an adjacency list
        vector<vector<int>> adj(c + 1, vector<int>());
        for (int i = 0; i < connections.size(); i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        // before dfs
        //  {1} -> {4}
        //  {2} -> {4,3}
        //  {4} -> {3,1,2}
        //  {3} -> {4,2}

        // we need vset, we can give adj, visited array,

        vector<shared_ptr<set<int>>> vset(c + 1);
        vector<int> visi(c + 1);
        for (int i = 1; i < adj.size(); i++) {
            if (visi[i] == 1)
                continue;
            set<int> temp;
            dfs(i, adj, visi, temp);
            temp.insert(i);
            // for every node in temp we are assigning it to every node;
            auto comp = make_shared<set<int>>(temp);
            for (int node : *comp) {
                vset[node] = comp; // all nodes share same set
            }
        }

        // after dfs
        //  {1} -> {4,3,2}
        //  {2} -> {2,3,1,4}
        //  {3} -> {4,1,2};
        //  {4} ->  {1,3,2};

        vector<int> ans;
        vector<int> vis(c + 1); // 0 is online // 1 is offline;
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] == 1) {
                if (vis[queries[i][1]] == 0) {
                    ans.push_back(queries[i][1]);
                } else {
                    while (vset[queries[i][1]] && !vset[queries[i][1]]->empty()) {
                        auto it = vset[queries[i][1]]->begin();
                        if (vis[*it] == 1)
                            vset[queries[i][1]]->erase(*it);
                        else {
                            ans.push_back(*it);
                            break;
                        }
                    }
                    if (vset[queries[i][1]] && vset[queries[i][1]]->empty()) {
                        ans.push_back(-1);
                    }
                }
            } else {
                vis[queries[i][1]] = 1;
            }
        }
        return ans;
    }
};