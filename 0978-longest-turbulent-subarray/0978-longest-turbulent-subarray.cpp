class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        //try two possibilites
        //first even -> arr[k] > arr[k+1] and odd -> arr[k] < arr[k+1];

        int streak = 0, maxStreak = 0;
        for(int i = 0; i < arr.size() - 1; i++){
            if(i % 2 == 0){
                if(arr[i] > arr[i+1]){
                    streak += 1;
                    maxStreak = max(maxStreak, streak);
                } else streak = 0;
            } else {
                if(arr[i] < arr[i + 1]){
                    streak += 1;
                    maxStreak = max(maxStreak, streak);
                } else streak = 0;
            }
        }
        
        int left = maxStreak;
        streak = 0;
        maxStreak = 0;
        for(int i = 0; i < arr.size() - 1; i++){
            if(i % 2 == 1){
                if(arr[i] > arr[i+1]){
                    streak += 1;
                    maxStreak = max(maxStreak, streak);
                } else streak = 0;
            } else {
                if(arr[i] < arr[i + 1]){
                    streak += 1;
                    maxStreak = max(maxStreak, streak);
                } else streak = 0;
            }
        }
        return max(left, maxStreak) + 1;
    }
};