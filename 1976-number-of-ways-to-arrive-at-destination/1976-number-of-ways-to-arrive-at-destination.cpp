class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //normal djikstra problem
        int mod = 1e9+7;
        //create an adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1] , roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0] , roads[i][2]});
        }
        //create a distance vector
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n);
        ways[0] = 1;
        dist[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> que;


        que.push({0,0});
        while(!que.empty()){
            auto [cost , node] = que.top();
            que.pop();
            if(dist[node] < cost) continue;

            for(pair i : adj[node]){
                if(dist[i.first] > i.second + cost){
                    //first time visiting node
                    dist[i.first] = cost + i.second;
                    ways[i.first] = ways[node];
                    que.push({cost + i.second , i.first});
                } else if(dist[i.first] == i.second + cost){
                    ways[i.first] = (ways[i.first] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};