class Solution {
public:
    bool isvowel(char ch) {
        return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') ||
               (ch == 'u') || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
    bool isValid(string word) {
        if (word.size() < 3)
            return false;

        bool alnum = false, vowel = false, consonant = false;
        for (char c : word) {
            if (!isalnum(c)){ return false;}
            else alnum = true;
            if(isvowel(c)) vowel = true;
            if(isalpha(c) && !isvowel(c)) consonant = true;
            // cout << c << endl;
        }

        return alnum && vowel && consonant;
    }
};