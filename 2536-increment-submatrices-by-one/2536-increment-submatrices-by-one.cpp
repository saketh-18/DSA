class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        //start from query[i][0] to query[i][2] -> rows
        //start from query[i][1] to query[i][3] > cols

        vector<vector<int>> vec(n,vector<int>(n));

        for(int i = 0; i < queries.size(); i++){
            for(int row = queries[i][0]; row <= queries[i][2]; row++){
                for(int col = queries[i][1]; col <= queries[i][3]; col++){
                    vec[row][col]++;
                }
            }
        }
        return vec;
    }
};