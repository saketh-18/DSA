#include <bits/stdc++.h>
class Solution {
public:
    string answerString(string word, int numFriends) {
        // find largest alphabet;
        // find largest string starting from that alphabet;
        // return that string;
        if (numFriends == 1) {
            return word;
        }

        queue<int> que;
        string ans = "";
        char maxChar = 'a';
        // vector<string> res;
        int maxLen = word.length() - numFriends + 1;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] > maxChar) {
                maxChar = word[i];
            }
        }

        for (int j = 0; j < word.length(); j++) {
            if (word[j] == maxChar) {
                que.push(j);
            }
        }

        string finalAns = "";
        while (!que.empty()) {
            int index = que.front();
            que.pop();
            int finalLen = min(maxLen, static_cast<int>(word.length() - index));

            // for (int i = index; i < index + finalLen; i++) {
            //     ans += word[i];
            // }
            ans = word.substr(index , finalLen);
            if (ans > finalAns) {
                finalAns = ans;
            }
            ans = "";

        }

        return finalAns;
    }
};