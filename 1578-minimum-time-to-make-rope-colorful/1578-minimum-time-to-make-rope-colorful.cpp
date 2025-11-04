class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
       int i = 0, j = 1;
       int ans = 0;

       while(i < j && j < colors.size()){
            if(colors[i] == colors[j]){
                if(neededTime[i] < neededTime[j]){
                    ans += neededTime[i];
                    i = j;
                } else {
                    ans += neededTime[j];
                }
            } else {
                i = j;
            }
            j++;
       }
       return ans;
    }
};