class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
         queue<pair<pair<int , int> , int>> que;
        vector<vector<int>> dist(mat.size() , vector<int>(mat[0].size() , 0));
        for(int i = 0 ; i < mat.size(); i++){
            for(int j = 0 ; j < mat[i].size(); j++){
                if(mat[i][j] == 1){
                    que.push({{i , j} , 0});
                }
            }
        }

        vector<pair<int,int>> delta = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!que.empty()){
            int r = que.front().first.first;
            int c = que.front().first.second;
            int steps = que.front().second;
            dist[r][c] = steps;
            que.pop();
            
            for(auto d : delta){
                int nrow = r + d.first;
                int ncol = c + d.second;

                if(nrow >= 0 && nrow < mat.size() && ncol >=0 && ncol < mat[nrow].size() && mat[nrow][ncol] == 0){
                    que.push({{nrow , ncol} , steps + 1});
                    mat[nrow][ncol] = -1;
                }
            }

        }

        return dist;

    }
};