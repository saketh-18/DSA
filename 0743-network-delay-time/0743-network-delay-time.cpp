class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //create an adjacency list
        //create a priority que for djikstra
        //do bfs

        vector<vector<pair<int,int>>> adj(n+1);
        for(int i = 0 ; i < times.size(); i++){
            adj[times[i][0]].push_back({times[i][1] , times[i][2]});
        }

        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        dist[0] = -1;
        pq.push({0,k});
        while(!pq.empty()){
            auto [cost,node] = pq.top();
            pq.pop();
            if(dist[node] < cost) continue;
            dist[node] = cost;

            for(auto i : adj[node]){
                if(dist[i.first] > cost + i.second){
                    dist[i.first] = cost+i.second;
                    pq.push({cost+i.second, i.first});
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < dist.size(); i++){
            if(dist[i] == INT_MAX) return -1;
            else ans = max(dist[i],ans);
        }
        return ans;
    }
};