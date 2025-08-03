class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
      if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
      if(grid.size()==1 && grid[0].size() == 1 && grid[0][0] == 0) return 1;
      queue<pair<pair<int,int>,int>> que;
      que.push({{0,0} , 1});
      grid[0][0] = 1;

      while(!que.empty()){
        auto [pos , dist] = que.front();
        que.pop();
        int r = pos.first;
        int c = pos.second;
        grid[r][c] = 1;

        vector<pair<int,int>> dir = {{0,1} , {0,-1} , {1,0} , {-1,0} , {1,1},{1,-1},{-1,1} ,{-1,-1}};
        for(pair i : dir){
            int nr = i.first + r;
            int nc = i.second + c;

            if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                if(grid[nr][nc] == 0){
                    if(nr == n-1 && nc == n-1) return dist+1;
                    que.push({{nr,nc},dist+1});
                }
            }
        }
      }  
      return -1;
    }
};