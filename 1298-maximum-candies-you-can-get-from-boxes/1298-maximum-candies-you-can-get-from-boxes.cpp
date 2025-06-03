class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
                    
        queue<int> q;
        vector<int> visited(status.size(), 0);
        map<int, int> m;
        unordered_set<int> deferred;
        int candiesTotal = 0;

        for (int i = 0; i < initialBoxes.size(); i++) {
            q.push(initialBoxes[i]);
            visited[initialBoxes[i]]++;
            if (status[initialBoxes[i]] == 1) {
                for (int j = 0; j < keys[initialBoxes[i]].size(); j++) {
                    m[keys[initialBoxes[i]][j]]++;
                }
            }
        }

        while (!q.empty()) {
            int temp = q.front();

            if (status[temp] == 1 || (status[temp] == 0 && m[temp] > 0)) {
                q.pop();
                if (status[temp] == 0)
                    status[temp] = 1; // Unlock it if we just got the key
                candiesTotal += candies[temp];

                // Add keys from this box
                for (int k : keys[temp]) {
                    m[k]++;
                }

                // Add contained boxes
                for (int b : containedBoxes[temp]) {
                    if (visited[b] == 0) {
                        q.push(b);
                        visited[b] = 1;
                    }
                }

            } else {
                q.pop();
                if (deferred.find(temp) == deferred.end()) {
                    q.push(temp);
                    deferred.insert(temp);
                }
            }
        }

        return candiesTotal;
    }
};
