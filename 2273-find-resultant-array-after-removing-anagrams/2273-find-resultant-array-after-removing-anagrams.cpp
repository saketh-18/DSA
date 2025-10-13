class Solution {
public:
    bool isvalid(string &word1, string &word2){
        vector<int> fre(26,0);

        for(char c : word1){
            fre[c-'a']++;
        }
        for(char c : word2){
            fre[c-'a']--;
        }

        for(int k : fre){
            if(k != 0) return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
       vector<string> ans;
       ans.push_back(words[0]);
       for(int i = 1; i < words.size(); i++){
            if(isvalid(ans.back(), words[i])) {
                cout << ans.back() << " " << words[i] << endl;
                cout << isvalid(ans.back(), words[i]);
                continue;
            }
            ans.push_back(words[i]);
       } 
       return ans;
    }
};