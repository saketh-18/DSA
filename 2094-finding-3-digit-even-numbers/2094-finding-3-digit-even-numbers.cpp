class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        map<int, int> digitCount;
        vector<int> res;

        for (int digit : digits) {
            digitCount[digit]++;
        }

        for (int num = 100; num <= 999; num += 2) {
            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            map<int, int> temp = digitCount;
            if (temp[a] > 0) {
                temp[a]--;
                if (temp[b] > 0) {
                    temp[b]--;
                    if (temp[c] > 0) {
                        res.push_back(num);
                    }
                }
            }
        }

        return res;
    }
};
