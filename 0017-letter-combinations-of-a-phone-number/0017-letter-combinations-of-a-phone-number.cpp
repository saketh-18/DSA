class Solution {
public:
    void dfs(string &digits, int i , string &cur, vector<string> &ans, vector<string> &nums){
        if(cur.length() == digits.length()){
            ans.push_back(cur);
            return ;
        }

        // if(i > digits.length()) return;

        for(char al : nums[digits[i]-'0']){
            cur.push_back(al);
            dfs(digits,i+1,cur,ans,nums);
            cout << cur << endl;
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> nums = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string cur;
        vector<string> ans;
        dfs(digits,0,cur,ans,nums);
        return ans;
    }
};