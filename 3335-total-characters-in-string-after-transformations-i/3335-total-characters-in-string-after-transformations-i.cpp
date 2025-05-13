class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        const int MOD = 1e9 + 7;

        while (t--) {
            vector<long long> next(26, 0);
            for (int i = 0; i < 25; ++i) {
                next[i + 1] = (next[i + 1] + freq[i]) % MOD;
            }
            next[0] = (next[0] + freq[25]) % MOD;
            next[1] = (next[1] + freq[25]) % MOD;
            freq = next;
        }

        long long total = 0;
        for (int i = 0; i < 26; ++i)
            total = (total + freq[i]) % MOD;

        return (int)total;
    }
};
