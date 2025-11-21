class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // sort right asc
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            if(a[1] == b[1]) {
                return a[0] > b[0];
            }
            else return a[1] < b[1];
        });

        // maintain two variables m n
        int m = -1, n = -1;
        int res = 0;
        for(int i = 0; i < intervals.size(); i++){
            if(n < intervals[i][0]){
                // we need to take two nums
                //one is right most and another is just before that i.e r and r-1
                m = intervals[i][1] - 1;
                n = intervals[i][1];
                res += 2;
            } else if(n >= intervals[i][0] && m < intervals[i][0]){
                // we only need to take on number
                // that is r
                m = n;
                n = intervals[i][1];
                res += 1;
            }           
        }
        return res;
    }
};