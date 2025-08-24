class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26,0);
        for(int i = 0 ; i < magazine.length(); i++){
            freq[magazine[i]-'a']++;
        }
        for(int i = 0; i < ransomNote.length(); i++){
            if(freq[ransomNote[i] - 'a'] != 0){
                freq[ransomNote[i]-'a']--;
            } else return false;
        }
        return true;
    }
};