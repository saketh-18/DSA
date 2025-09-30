class Solution {
public:
    bool rec(int i, string &s, unordered_map<string,int> &hash, string temp, vector<vector<int>> &dp){
        if(i == s.size()){
            if(hash.find(temp) != hash.end()) return true;
            return false;
        }

        if(dp[i][temp.size()] != -1) return dp[i][temp.size()];
        if(hash.find(temp) != hash.end()){
            return dp[i][temp.size()] = rec(i+1,s,hash,string(1, s[i]),dp) || rec(i+1,s,hash,temp+s[i],dp);
        }
        return dp[i][temp.size()] = rec(i+1,s,hash,temp+s[i],dp);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> hash;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        for(string s : wordDict){
            hash[s]++;
        }

        return rec(0,s,hash,"",dp);
    }
};