class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int xsum) {
        unordered_map<int, int> fre;
        multiset<pair<int, int>, greater<pair<int, int>>> top;
        multiset<pair<int, int>, greater<pair<int, int>>> low;

        int n = nums.size();

        for (int i = 0; i < k; i++) {
            fre[nums[i]]++;
        }

        int times = n - k + 1;
        long long x = 0;
        vector<long long> ans(times);

        for (auto& p : fre) {
            if (top.size() < xsum) {
                top.insert({p.second, p.first});
                x += 1LL * ((long long)p.first * (long long)p.second);
            } else {
                top.insert({p.second, p.first});
                x += 1LL * ((long long)p.first * (long long)p.second);
                auto it = prev(top.end());
                x -= 1LL * ((long long) it->first * (long long) it->second);
                low.insert(*it);
                top.erase(it);
            }
        }

        ans[0] = x;
        for (int i = 1; i < times; i++) {
            int in = nums[i + k - 1];
            int out = nums[i - 1];
            if (in == out) {
                ans[i] = ans[i - 1];
                continue;
            }
            int oldfre = fre[out];

            auto itTop = top.find({oldfre, out});
            auto itLow = low.find({oldfre, out});

            if (itTop != top.end()) {
                x -= 1LL * out * oldfre;
                top.erase(itTop);
            } else if (itLow != low.end()) {
                low.erase(itLow);
            }

            fre[out]--;

            // check if the new element exists in frequency map

            int oldinfre = 0;
            if (fre.find(in) != fre.end())
                oldinfre = fre[in];

            if (oldinfre > 0) {
                auto it_erase = top.find({oldinfre, in});
                auto it_erase_low = low.find({oldinfre, in});

                if (it_erase != top.end()) {
                    x -= 1LL * in * oldinfre;
                    top.erase(it_erase);
                } else if (it_erase_low != low.end()) {
                    low.erase(it_erase_low);
                }
            }

            fre[in]++;

            // insert out

            if (fre[out] > 0) {
                pair<int, int> newPair = {fre[out], out};
                if (top.size() < xsum) {
                    top.insert(newPair);
                    x += 1LL * fre[out] * out;
                } else {
                    auto it_smallest_top = prev(top.end());
                    if (newPair > *it_smallest_top) {
                        x -= 1LL * it_smallest_top->first *
                             it_smallest_top->second;
                        low.insert(*it_smallest_top);
                        top.erase(it_smallest_top);
                        top.insert(newPair);
                        x += 1LL * fre[out] * out;
                    } else {
                        low.insert(newPair);
                    }
                }
            }

            // insert in
            pair<int, int> newPair = {fre[in], in};
            if (top.size() < xsum) {
                top.insert(newPair);
                x += 1LL * fre[in] * in;
            } else {
                auto it_smallest_top = prev(top.end());
                if (newPair > *it_smallest_top) {
                    low.insert(*it_smallest_top);
                    x -= 1LL * it_smallest_top->first * it_smallest_top->second;
                    top.erase(it_smallest_top);
                    top.insert(newPair);
                    x += 1LL * fre[in] * in;
                } else {
                    low.insert(newPair);
                }
            }

            while (top.size() > xsum) {
                auto it_smallest = prev(top.end());
                x -= 1LL * it_smallest->first * it_smallest->second;
                low.insert(*it_smallest);
                top.erase(it_smallest);
            }

            while (top.size() < xsum && !low.empty()) {
                auto it_largest = low.begin();
                top.insert(*it_largest);
                x += 1LL * it_largest->first * it_largest->second;
                low.erase(it_largest);
            }

            while (!top.empty() && !low.empty() &&
                   *low.begin() > *prev(top.end())) {
                auto lo = *low.begin();     // best in low
                auto hi = *prev(top.end()); // worst in top

                // move hi -> low
                x -= 1LL * hi.first * hi.second;
                low.erase(low.begin()); // we'll erase lo after using it
                low.insert(hi);

                // move lo -> top
                top.erase(prev(top.end()));
                top.insert(lo);
                x += 1LL * lo.first * lo.second;
            }

            ans[i] = x;
        }
        return ans;
    }
};