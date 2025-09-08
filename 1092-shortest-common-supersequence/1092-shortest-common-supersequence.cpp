class Solution {
public:
    string buildSupersequence(string& str1, string& str2, string& lcs) {
        string result;
        int i = 0, j = 0;

        for (char c : lcs) {
            // add everything from str1 until c
            while (i < str1.size() && str1[i] != c) {
                result.push_back(str1[i++]);
            }
            // add everything from str2 until c
            while (j < str2.size() && str2[j] != c) {
                result.push_back(str2[j++]);
            }
            // add the common character
            result.push_back(c);
            i++;
            j++;
        }

        // add leftovers
        result += str1.substr(i);
        result += str2.substr(j);

        return result;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        string lcs;
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (str1[i-1] == str2[j-1]) {
                lcs.push_back(str1[i-1]);
                i--; j--;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
        reverse(lcs.begin(), lcs.end());
        if (dp[n][m] == 0) return str1 + str2;
        return buildSupersequence(str1, str2, lcs);
    }
};