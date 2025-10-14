class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (2 * k > nums.size())
            return false;

        int count = 0;
        int prev = INT_MIN;
        bool justnow = false;
        for (int i : nums) {
            if (i > prev) {
                count++;
                if (justnow) {
                    if (count == k)
                        return true;
                }
                if (count == 2 * k)
                    return true;
            }

            if (i <= prev) {
                if (count >= k) {
                    justnow = true;
                } else
                    justnow = false;
                count = 1;
            }
            prev = i;
        }

        if (count >= k && justnow)
            return true;
        return false;
    }
};
