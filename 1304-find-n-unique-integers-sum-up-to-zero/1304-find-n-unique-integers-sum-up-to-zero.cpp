class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 1) return {0};

        if(n%2 == 0){
            vector<int> ans;
            for(int i = 1; i < n; i+=2){
                ans.push_back(-i);
                ans.push_back(i);
            }
            return ans;
        } else {
            vector<int> ans;
            for(int i = 1; i < n; i+=2){
                ans.push_back(-i);
                ans.push_back(i);
            }
            ans.push_back(0);
            return ans;
        }
    }
};