#include <bits/stdc++.h>
class Solution {
public:
    string largestGoodInteger(string num) {
        int smax = -1;
        string ans = "";
        for(int i = 0 ; i < num.length() - 2; i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                if(stoi(num.substr(i,3)) > smax) {
                    ans = num.substr(i,3);
                    smax = stoi(num.substr(i,3));
                }
            }
        }
        return ans;
    }
};