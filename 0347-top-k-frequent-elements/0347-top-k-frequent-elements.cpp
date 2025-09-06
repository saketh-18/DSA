class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> fre;

        for(int i : nums){
            fre[i]++;
        }

        multimap<int,int> real;
        for(auto it = fre.begin(); it != fre.end(); ++it){
            real.insert({it->second,it->first});
        }
        vector<int> ans(k);
        int i = 0;

        for(auto it = real.rbegin(); it != real.rend(); ++it){
            if(i < k){
                ans[i] = it->second;
                i++;
            }
        }

        return ans;
    }
};