class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        //length = nums.size() - k + 1;
        // we need to perform n*(n - k + 1);
        int n = nums.size();
        vector<int> vis(51, 0);
        int times = n - k + 1;
        vector<int> ans(times);
        for(int i = 0; i < times; i++){
            fill(vis.begin(), vis.end(), 0);
            for(int j = i; j < i + k; j++){
                vis[nums[j]]++;
            }

            multiset<pair<int, int>, greater<pair<int, int>>> hash;

            for(int f = 1; f < 51; f++){
                if(vis[f] != 0){
                    hash.insert({vis[f], f});
                }
            }

            int s = x;
            for (auto it = hash.begin(); it != hash.end(); ++it) {
                if(s <= 0) break;
                auto pair = *it;
                ans[i] += (pair.first) * (pair.second);
                s--;
            }
        }
        return ans;
    }
};