#include<string>
class Solution {
public:
    bool ispal(string s){
        int i = 0 , j = s.length() - 1;
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void dfs(string &a , int i, vector<vector<string>> &ans, vector<string> &temp){
        if(i >= a.length()){
            ans.push_back(temp);
            return;
        };

        for(int k = 1; k <= a.length() - i; k++){
            //partitioning each with length from k to a.length();
            string cur = a.substr(i,k);
            if(ispal(cur)){
                cout << cur << endl;
                temp.push_back(cur);
                dfs(a,i+k,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        dfs(s,0,ans,temp); 
        return ans;
    }
};