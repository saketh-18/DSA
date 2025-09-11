class Solution {
public:
    bool chk (char &c) {
        switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
        }
    }
    string sortVowels(string s){
        string vowels = "";

        for (int i = 0; i < s.size(); i++){
            if(chk(s[i])){
                vowels += s[i];
                s[i] = '_';
            }
        }

        sort(vowels.begin(),vowels.end());
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '_'){
                s[i] = vowels[j];
                j++;
            }
        }

        return s;
    }
};