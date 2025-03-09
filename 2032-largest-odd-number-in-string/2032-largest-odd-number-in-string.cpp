class Solution {
public:
    string largestOddNumber(string num) {
        set<char> numSet = {'1', '3', '5', '7', '9'}; // Define the set
        for(int i = num.length() - 1; i >= 0 ; i--){
            if(numSet.find(num[i]) != numSet.end()){
                return num.substr(0 , i+1);
            }
        }
        return "";
    }
};