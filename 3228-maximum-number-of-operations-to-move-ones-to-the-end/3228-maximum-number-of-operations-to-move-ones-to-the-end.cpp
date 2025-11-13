class Solution {
public:
    int maxOperations(string s) {
        int ops = 0;
        int cons = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1') cons++;
            else {
                ops += cons;
                while(i < s.size() && s[i] == '0'){
                    i++;
                }
                if(i > 0) i--;
            }
        }

        return ops;
    }
};