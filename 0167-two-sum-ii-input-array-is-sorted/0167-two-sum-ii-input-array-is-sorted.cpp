class Solution {
public:
    int bs(vector<int>& numbers, int x, int l, int h) {
        if (l > h)
            return -1;
        int mid = (h + l) / 2;
        if (numbers[mid] == x)
            return mid;
        else if (numbers[mid] > x) {
            return bs(numbers, x, l, mid - 1);
        } else
            return bs(numbers, x, mid + 1, h);
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first = 0;
        for (int i = 0; i < numbers.size(); i++) {
            first = numbers[i];
            if(first == target - first) return {i+1 , i+2};
            int res = bs(numbers, target - first, i, numbers.size() - 1);
            if (res != -1) {
                return {i + 1, res + 1};
            }
        }
        return {-1};
    }

}
;