class Solution {
public:
    vector<int> partitionLabels(string s) {
        //a map of every character's last index
        unordered_map<char,int> hash;
        for(int i = 0; i < s.size(); i++){
            hash[s[i]] = i;
        }

        vector<int> ans;
        int l = 0, r = hash[s[0]];
        // the min length of first subset would be r - l + 1
        while(l < s.size() && r < s.size()){
            //check if the substring contains any other characters
            if(hash[s[l]] == l){
                ans.push_back(1);
                l++;
                r = hash[s[l]];
                continue;
            }
                for(int i = l; i <= r; i++){
                    r = max(hash[s[i]],r);
                }
                ans.push_back(r-l + 1);
                l = r + 1;
                r = hash[s[l]];
        }
        return ans;
    }
};