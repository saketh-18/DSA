class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prev = 0, temp = 0;
        for(int i = 0; i < bank.size(); i++){
            prev = temp;
            temp = 0;
            for(char c : bank[i]){
                if(c == '1') temp++;
            }
            if(prev == 0) continue;
            if(temp == 0){
                temp = prev;
                continue;
            }
            if(temp > 0){
                ans += (temp*prev);
            }
        }
        return ans;
    }
};