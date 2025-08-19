class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> des = strs;
        for(int i = 0; i < strs.size(); i++){
            sort(strs[i].begin(),strs[i].end());
        }
        map<string,int> ana;
        vector<vector<string>> ans;
        for(int i = 0 ; i < strs.size();i++){
            if(strs[i] == "@") continue;
            vector<string> temp;
            temp.push_back(des[i]);
            for(int j = i + 1; j < strs.size(); j++){
                if(strs[i] == strs[j]){
                    temp.push_back(des[j]);
                    strs[j] = "@";
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};