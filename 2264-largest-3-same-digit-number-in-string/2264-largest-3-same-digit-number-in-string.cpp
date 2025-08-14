#include <bits/stdc++.h>
class Solution {
public:
    string largestGoodInteger(string num) {
        char smax = '\0';
        string ans = "";
        for(int i = 0 ; i < num.length() - 2; i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                smax = max(smax, num[i]);
            }
        }
        if(smax == '\0') return "";
        else return string(3,smax);
    }
};