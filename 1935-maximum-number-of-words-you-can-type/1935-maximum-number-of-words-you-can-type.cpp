class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int i = 0, ans = 0;
        unordered_map<char,int> bro;
        for(char c : brokenLetters){
            bro[c]++;
        }
        while(i < text.length()){
            bool can = true;
            while(i < text.size() && text[i] != ' '){
                if(bro.find(text[i]) != bro.end()){
                   can = false;
                }
                i++;
            }
            if(can) ans++;
            i++;
        }
        return ans;
    }
};