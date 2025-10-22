class Solution {
public:
    int hammingWeight(int n) {
        vector<int> binary(32);

        int i = 0;
        int count = 0;
        while(n > 0){
            binary[i] = n%2;
            if(binary[i] == 1) count++;
            n /= 2;
            i++;
        }
        return count;
    }
};