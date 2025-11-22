class Solution {
public:
    int countPalindromicSubsequence(string s) {
        //map all the occurences of string
        unordered_map<char,vector<int>> hash;
        for(int i = 0; i < s.size(); i++){
            if(hash[s[i]].size() <= 1){
                hash[s[i]].push_back(i);
            } else {
                hash[s[i]][1] = i;
            }
        }

        int ans = 0;
        unordered_map<char,int> mp;
        for(char i : s){
            if(mp.find(i) != mp.end()) continue;
            mp[i]++;
            if(hash[i].size() == 2){
                if(hash[i][1] - hash[i][0] > 1){
                    cout << i << endl;
                    cout << hash[i][0] << " " << hash[i][1] << endl;
                    set<char> st;
                    for(int j = hash[i][0] + 1; j < hash[i][1]; j++){
                        st.insert(s[j]);
                    }
                    ans += st.size();
                }
            }
        }
        return ans;
    }
};