class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;
        string vowels = "aeiou";
        for(char c : s){
            if(vowels.find(c) != string::npos) return true;
        } 
        return false;
    }
};