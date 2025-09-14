#include <bits/stdc++.h>

class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string lowerT(string &s){
        for(int i = 0; i < s.length(); i++){
            s[i] = tolower(s[i]);
        } return s;
    }
    string vowelT(string &s){
        for(int i = 0; i < s.length(); i++){
            s[i] = tolower(s[i]);
            if(isVowel(s[i])){
                s[i] = '*';
            }
        } return s;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string,int> word;
        vector<string> ans;
        //store
        for(int i = wordlist.size()-1; i >= 0; i--){
           word[wordlist[i]] = i; // storing original
           string lower = "#";
           string vowel = "";
           for (char c : wordlist[i]){
                c = tolower(c);
                lower += c;
                if(isVowel(c)){
                    vowel += '*';
                } else vowel += c;
           }
           word[lower] = i;
           word[vowel] = i;
        }

        //check
        for(string s : queries){
            //check for original
            if(word.find(s) != word.end()){
                ans.push_back(s);
            } else {
                string lower = "#";
                lower += lowerT(s);
                string vowel = vowelT(s);
                if(word.find(lower) != word.end()){
                    ans.push_back(wordlist[word[lower]]);
                }
                else if(word.find(vowel) != word.end()){
                    ans.push_back(wordlist[word[vowel]]);
                } else ans.push_back("");
            }
        }
        return ans;
    }
};



//store original
//store all small
//store vowel asterisk