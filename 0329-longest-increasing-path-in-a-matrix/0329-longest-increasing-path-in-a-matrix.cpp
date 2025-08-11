class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //create a que and store all the elements in matrix
        //do bfs from every node and if no greater element present in the neighbors then drop the node
        //store node , parent and distance in the que
        //we need to store the pos , parent  , distance 
        //i,j,parent,distance
        int rows = matrix.size();
        int cols = matrix[0].size();
        queue<pair<pair<int,int>,int>> que;
        for(int i = 0 ; i < rows; i++){
            for(int j = 0 ; j < cols; j++){
                que.push({{i,j},1});
            }
        }

        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        int maxDistance = 1;
        while(!que.empty()){
            auto [node, dist] = que.front();
            int row = node.first;
            int col = node.second;

            que.pop();

            for(auto i : dir){
                int nr = row + i.first;
                int nc = col + i.second;

                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols){
                    if(matrix[nr][nc] > matrix[row][col]){
                        maxDistance = max(maxDistance , dist + 1);
                        que.push({{nr,nc},dist + 1});
                    }
                }
            }
        }
        return maxDistance;
    }
};