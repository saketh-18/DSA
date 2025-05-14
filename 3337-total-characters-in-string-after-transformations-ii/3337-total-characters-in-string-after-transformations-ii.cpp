class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        const int MOD = 1e9 + 7;
        using ll = long long;

        vector<ll> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        while (t-- > 0) {
            vector<ll> diff(26, 0);
            for (int i = 0; i < 26; ++i) {
                if (freq[i] == 0 || nums[i] == 0) continue;
                ll val = freq[i] % MOD;

                int l = (i + 1) % 26;
                int r = (i + nums[i] + 1) % 26;

                diff[l] = (diff[l] + val) % MOD;
                diff[r] = (diff[r] - val + MOD) % MOD;

                if (l > r) {
                    diff[0] = (diff[0] + val) % MOD;
                }
            }

            // Convert diff to actual values using prefix sum
            vector<ll> next(26, 0);
            ll run = 0;
            for (int i = 0; i < 26; ++i) {
                run = (run + diff[i]) % MOD;
                next[i] = run;
            }

            freq = next;
        }

        ll result = 0;
        for (ll val : freq) {
            result = (result + val) % MOD;
        }

        return (int)result;
    }
};
