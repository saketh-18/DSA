#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int recursion(string s, int i , long ans , int sign){
        if(!isdigit(s[i])) return ans;
        if(i >= s.size()) return (int)(ans);
        ans = ans*10 + (s[i] - '0');
        if(sign*ans > INT_MAX) return INT_MAX;
        if(sign*ans < INT_MIN) return INT_MIN;
        return recursion(s , i+1 , ans , sign);
    }
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long res = 0; // Using long to handle overflow cases

        // Trim leading spaces
        while (i < s.size() && s[i] == ' ') i++;
        if (i == s.size()) return 0;

        // Check for sign
        if (s[i] == '-') { sign = -1; i++; }
        else if (s[i] == '+') i++;

        // Process numerical characters
        res = recursion(s , i , res , sign);

        return (int)(sign*res);
    }
};