class Solution {
public:
    bool check(char c){
        switch(c){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
        }
        return false;
    }
    bool doesAliceWin(string s) {
        int count = 0;
        for(char c : s){
            if(check(c)){
                count++;
            }
        } 
        return !(count == 0);
    }
};