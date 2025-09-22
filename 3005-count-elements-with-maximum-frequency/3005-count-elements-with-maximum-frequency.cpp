class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> fre;
        int max = 0 ,ans = 0;
        for(int i : nums){
            fre[i]++;
            if(fre[i] > max){
                max = fre[i];
                ans = max;
            } else if(fre[i] == max){
                max = fre[i];
                ans += max;
            }
        }
        return ans;
    }
};